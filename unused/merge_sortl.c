/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_seq_tree
{
	struct s_seq_tree	*parent;
	struct s_seq_tree	*child[2];
	int					len;
	int					head_val;
	int					**stack;
	char				stack_name;
	int					child_n;
}	t_tree_node;

void	merge_2(int **stack, int size)
{
	if (stack[1])
	{
		if (*stack[0] > *stack[1] && size == 2)
			swap_a(stack);
	}
}

bool	is_sequence_sorted(int **stack, int len, int sign)
{
	int	i;

	i = 1;
	while (stack[i - 1] && stack[i] && len > 1)
	{
		if (*stack[i - 1] * sign > *stack[i] * sign)
			return (false);
		i++;
		len--;
	}
	return (true);
}

int	store_est_in_stack(int **main, int **secondary, int dir, int size)
{
	int	i;

	i = 0;
	while (*main && *secondary && size--)
	{
		if (**main * dir < **secondary * dir)
		{
			push_name(main, secondary, 'a' + (-sign(dir - 1)));
			i++;
		}
		else
			break ;
	}
	return (i);		 
}

int	store_highest_in_a(t_data *data, int size)
{
	return(store_est_in_stack(data->stack_a, data->stack_b, 1, size));
}

int	store_lowest_in_b(t_data *data, int size)
{
	int	appended;

	appended = store_est_in_stack(data->stack_b, data->stack_a, -1, size);
	return (appended);
}

int	prepare_for_merge_b(t_data *data, int size)
{
	int target_a;
	int	target_b;
	int	dist_a;
	int	dist_b;

	if (!*data->stack_b)
		return (0);
	target_a = find_lowest_size(data->stack_a, size);
	target_b = find_lowest_size(data->stack_b, size);
	if (*data->stack_b[target_b] < *data->stack_a[target_a])
		target_b = next(data->stack_b, target_b);
	dist_a = get_distance(data->stack_a, 0, target_a);
	dist_b = get_distance(data->stack_b, 0, target_b);
	if (abs(dist_a) + abs(dist_b) < min(abs(dist_a), abs(dist_b))
		+ abs(get_distance(data->stack_a, target_a, target_b)))
	{
		rotate_to_goal_flag(data, 0, target_a, 1);
		rotate_to_goal_flag(data, 0, target_b, -2);
	}
	else
		syncronized_rotation (data, target_a, target_b);
	return (store_lowest_in_b(data, size));
}

int	prepare_for_merge_a(t_data *data, int size_a, int size_b)
{
	int	target_a;
	int	target_b;
	int	dist_a;
	int	dist_b;

	if (!*data->stack_a)
		return (0);
	target_a = find_highest_size(data->stack_a, size_a);
	target_b = find_highest_size(data->stack_b, size_b);
	if (*data->stack_a[target_a] < *data->stack_b[target_b])
		target_a = next(data->stack_a, target_a);
	else
	{
		while (target_a > 0 && *data->stack_a[target_a - 1]
			> *data->stack_b[target_b])
			target_a--;
	}
	dist_a = get_distance(data->stack_a, 0, target_a);
	dist_b = get_distance(data->stack_b, 0, target_b);
	if (abs(dist_a) + abs(dist_b) <= min(abs(dist_a), abs(dist_b))
		+ abs(get_distance(data->stack_a, target_a, target_b)))
	{
		rotate_to_goal_flag(data, target_a, 0, 1);
		rotate_to_goal_flag(data, target_b, 0, -2);
	}
	else
		syncronized_rotation (data, target_a, target_b);
	return (store_highest_in_a(data, size_a));
}

bool	merge_backtrack_check(int **main_s, int **secondary, int main_len, int dir)
{
	int	last_val;

	if (main_len <= 1)
		return (true);
	last_val = *main_s[previous(main_s, 0)];
	if (**secondary * dir > last_val * dir)
		return (true);
	if (**main_s *dir < last_val * dir)
		return (true);
	return (false);
}

void	merge_size(int **main_s, int **secondary, int size, int dir)
{
	int		main_len;
	char	name_main;

	name_main = 'a' + (-sign(dir - 1));
	main_len = stack_len(main_s);
	while (size > 0)
	{
		if (!*main_s)
		{
			push_name(main_s, secondary, name_main);
			main_len++;
			size--;
		}
		else if (*secondary)
		{
			if (**main_s * dir > **secondary * dir && merge_backtrack_check(main_s, secondary, main_len, dir))
			{
				push_name(main_s, secondary, name_main);
				main_len++;
				size--; 
			}
			else
				rotate_name(main_s, -1, main_len, name_main);
		}
		else
		{
			rotate_name(main_s, -1, main_len, name_main);
			size--;
		}
	}
}

void	merge_a(t_data *data, int size, int parent_size)
{
	int	head_val;
	int	temp;

	if (*data->stack_a[0] < *data->stack_b[parent_size - size - 1])
		head_val = *data->stack_a[0];
	else
		head_val = *data->stack_b[parent_size - size - 1];
	temp = prepare_for_merge_a(data, size, parent_size - size);
	merge_size(data->stack_a, data->stack_b, parent_size - size - temp, 1);
	temp = find_of_value(data->stack_a, head_val);
	rotate_to_goal_flag(data, temp, 0, 1);
}


void	merge_b(t_data *data, int size)
{
	merge_size(data->stack_b, data->stack_a, size, -1);
}

void	repeat_push(int **main, int **secondary, void (*f)(int**,int**), int times)
{
	while (times)
	{
		f(main, secondary);
		times--;
	}
}

/*typedef struct s_seq_tree
{
	struct s_seq_tree	*parent;
	struct s_seq_tree	*chid[2];
	int					len;
	int					head_val;
	int					**stack;
	char				stack_name;
	int					child_n;
}	t_tree_node;
*/

t_tree_node	*tree_node_init(t_tree_node *parent, int child_n)
{
	t_tree_node *child;

	child = malloc(sizeof(struct s_seq_tree));
	if (!child)
		return (NULL);
	child->parent = parent;
	child->child[0] = NULL;
	child->child[1] = NULL;
	if (child_n == 1)
	{
		child->head_val = *parent->stack[0];
		child->len = parent->len / 2;
	}
	else
	{
		child->head_val = *parent->stack[parent->child[0]->len];
		child->len = parent->len - parent->child[0]->len;
	}
	child->stack = parent->stack;
	child->stack_name = parent->stack_name;
	child->child_n = child_n;
	return (child);
}

void	split_sequence(t_data *data, t_tree_node *sequence)
{
	sequence->child[0] = tree_node_init(sequence, 0);
	if (!sequence->child[0])
		return ;
	sequence->child[1] = tree_node_init(sequence, 1);
	if (!sequence->child[1])
		return ;
	merge(data, sequence->child[0]);
	merge(data, sequence->child[1]);
}

void	sorted_seq_logic(t_tree_node *sequence)
{
	
}

void	merge(t_data *data, t_tree_node *sequence)
{
	if (is_sequence_sorted(sequence->stack, sequence->len,
	 1 + (-2 * sequence->stack_name - 'a')))
	{
		if (sequence->parent == NULL)
			return ;
		sorted_seq_logic(sequence);		
	}
	else
	{
		if (sequence->len <= 2)
			solve_2_any(sequence->stack, sequence->stack_name);
		else if (sequence->len == 3)
			solve_3_any(sequence->stack, sequence->stack_name);
		else
			split_sequence(data, sequence);
		merge(data, sequence);
	}
}

t_tree_node	*init_tree(t_data *data)
{
	t_tree_node *head;

	head = malloc(sizeof(struct s_seq_tree));
	if (!head)
		return (NULL);
	head->parent = NULL;
	head->child[0] = NULL;
	head->child[1] = NULL;
	head->len = data->tot_len;
	head->head_val = **data->stack_a;
	head->stack_name = 'a';
	head->child_n = 1;
	return (head);
}

void	merge_sort(t_data *data)
{
	t_tree_node	*tree_head;

	tree_head = init_tree(data);
	if (!tree_head)
		return ;
	merge(data, tree_head);
}
