/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_5_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/03/30 23:55:22 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef RADIX
# define RADIX 10
#endif

typedef struct s_seq_list
{
	struct s_seq_list *parent;
	struct s_seq_list *child;
	int len;
	int highest_val;
	int lowest_val;
	int **stack;
	char stack_name;
} t_list_node;

void free_list(t_list_node *list)
{
	t_list_node *next;

	if (!list)
		return;
	while (list)
	{
		next = list->child;
		free(list);
		list = next;
	}
}

t_list_node *get_n_child(t_list_node *list, int n)
{
	t_list_node *next;

	if (n < 0)
		n = __INT_MAX__;
	if (list && n)
		next = list->child;
	else
		next = NULL;
	while (n-- && next)
	{
		list = next;
		next = list->child;
	}
	return (list);
}

int free_all(t_data *data, t_list_node *list)
{
	free_data(data);
	free_list(list);
	return (1);
}

t_list_node *free_node(t_list_node *node)
{
	t_list_node *temp;

	temp = NULL;
	if (node)
	{
		if (node->parent && node->child)
		{
			temp = node->child;
			node->parent->child = node->child;
			node->child->parent = node->parent;
		}
		else if (node->child)
		{
			node->child->parent = NULL;
			temp = node->child;
		}
		else if (node->parent)
			node->parent->child = NULL;
		free(node);
	}
	return (temp);
}

void repeat_push(int **main, int **secondary, void (*f)(int **, int **), int times)
{
	while (times)
	{
		f(main, secondary);
		times--;
	}
}

/*typedef struct s_seq_list
{
	struct s_seq_list	*parent;
	struct s_seq_list	*chid[2];
	int					len;
	int					first_val;
	int					**stack;
	char				stack_name;
	int					child_n;
}	t_list_node;
*/

t_list_node *node_init(t_list_node *parent, int pivot)
{
	t_list_node *child;

	child = malloc(sizeof(struct s_seq_list));
	if (!child)
		return (NULL);
	child->parent = parent;
	child->child = NULL;
	child->highest_val = parent->highest_val;
	child->lowest_val = pivot;
	parent->highest_val = pivot - 1;
	child->len = child->highest_val - child->lowest_val + 1;
	parent->len = parent->len - child->len;
	child->stack = parent->stack;
	child->stack_name = parent->stack_name;
	return (child);
}

t_list_node *split_n_times(t_list_node *parent, int times)
{
	t_list_node *current;
	int len;
	int original_len;

	original_len = parent->len;
	len = original_len / times;
	current = parent;
	while (current && times > 1)
	{
		current->child = node_init(current, current->lowest_val + len);
		current = current->child;
		times--;
	}
	if (!current)
		return (NULL);
	return (current);
}

t_list_node *list_init(t_data *data)
{
	t_list_node *head;

	head = malloc(sizeof(struct s_seq_list));
	if (!head)
		return (NULL);
	head->parent = NULL;
	head->child = NULL;
	head->len = data->tot_len;
	head->highest_val = data->tot_len;
	head->lowest_val = 1;
	head->stack_name = 'a';
	head->stack = data->stack_a;
	return (head);
}

// i want to push and rotate n % 5 =  2
// i want to push n % 5 = 3

void divide_in_three(t_data *data, int radix, int *metric)
{
	int start;
	int eq_result;
	int **stack;
	char name;

	stack = data->stack_a;
	name = 'a';
	// temp = *list->stack[previous(list->stack, 0)];
	start = **stack;
	eq_result = start / radix % RADIX;
	while (eq_result == metric[0] || eq_result == metric[1])
	{
		push_other(data, name);
		if (eq_result == metric[0] && *stack_from_name(data,
			opposite_name(name)))
			rotate_other(data, name, 1);
		start = **stack;
		eq_result = start / radix % RADIX;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		eq_result = **stack / radix % RADIX;
		if (eq_result == metric[0])
		{
			if (!stack[1] || ((*stack[1] / radix % RADIX == metric[1] || *stack[1] / radix % RADIX == metric[0]) && *stack[1] != start))
			{
				push_other(data, name);
				rotate_other(data, name, 1);
			}
			else
			{
				push_other(data, name);
				rotate_both(data->stack_a, data->stack_b, 1);
			}
		}
		else if (eq_result == metric[1])
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

void divide_in_three_neg(t_data *data, int radix, int *metric)
{
	int start;
	int eq_result;
	int **stack;
	char name;

	stack = data->stack_b;
	name = 'b';

	// temp = *list->stack[previous(list->stack, 0)];
	start = **stack;
	eq_result = start / radix % RADIX;
	while (eq_result == metric[0] || eq_result  == metric[1])
	{
		push_other(data, name);
		if (eq_result == metric[0] &&
			*stack_from_name(data, opposite_name(name)))
			rotate_other(data, name, 1);
		start = **stack;
		eq_result = start / radix % RADIX;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		eq_result = **stack / radix % RADIX;
		if (eq_result == metric[0])
		{
			if (!stack[1] || ((*stack[1] / radix % RADIX == metric[1] || *stack[1] / radix % RADIX == metric[0]) && *stack[1] != start))
			{
				push_other(data, name);
				rotate_other(data, name, 1);
			}
			else
			{
				push_other(data, name);
				rotate_both(data->stack_a, data->stack_b, 1);
			}
		}
		else if (eq_result == metric[1])
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

int *get_metric(int *metric)
{
	static int i;

	if (i % 4 == 2)
	{
		metric[0] = 3;
		metric[1] = 2;
	}
	else if (i % 4 == 3)
	{
		metric[0] = 4;
		metric[1] = 1;
	}
	else if (i % 4 == 1)
	{
		metric[0] = 0;
		metric[1] = 3;
	}
	else if (i % 4 == 0)
	{
		metric[0] = 1;
		metric[1] = 2;
	}
	i++;
	return (metric);
}

static void	divide_in_two(t_data *data, int metric, char name, int sig_digit)
{
	int	start;
	int	**stack;

	stack = stack_from_name(data, name);
	if (sig_digit > data->tot_len * 2)
		return ;
	start = **stack;
	while (start / sig_digit % RADIX == metric && *stack)
	{
		push_other(data, name);
		start = **stack;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		if (**stack / sig_digit % RADIX == metric)
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

void base_3_radix(t_data *data)
{
	// p_quick_sort(data, list_head);
	if (data->tot_len <= 500)
	{
		int radix;
		char name;

		name = 'a';
		radix = 1;
		while (radix < data->tot_len)
		{
			if (name == 'a')
			{
				divide_in_two(data, 0, name, radix);
				divide_in_two(data, 1, name, radix);
			}
			else
			{
				divide_in_two(data, 2, name, radix);
				divide_in_two(data, 1, name, radix);
			}
			// if (radix * RADIX > data->tot_len)
			// 	name = opposite_name(name);
			while (*stack_from_name(data, name))
				push_other(data, name);
			radix *= RADIX;
			name = opposite_name(name);
		}
	}
}

void	base_n_radix(t_data *data)
{
	// int metric[2];

	// p_quick_sort(data, list_head);
	if (data->tot_len <= 500)
	{
		int radix;
		char name;
		int		i;

		name = 'a';
		radix = 1;
		while (radix < data->tot_len)
		{
			if (name == 'a')
			{
				i = 0;
				while (i < RADIX - 1)
				{
					divide_in_two(data, i, name, radix);
					i++;
				}
			}
			else
			{
				i = RADIX - 1;
				while (i)
				{
					divide_in_two(data, i, name, radix);
					i--;
				}
			}
			while (*stack_from_name(data, name))
				push_other(data, name);
			radix *= RADIX;
			name = opposite_name(name);
		}
	}
}