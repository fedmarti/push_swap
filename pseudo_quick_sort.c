/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/21 01:12:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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



void merge_2(int **stack, int size)
{
	if (stack[1])
	{
		if (*stack[0] > *stack[1] && size == 2)
			swap_a(stack);
	}
}

bool is_sequence_sorted(int **stack, int len, int sign)
{
	int i;

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

	if (!parent)
		return (NULL);
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

// void	sorted_seq_logic(t_list_node *sequence)
// {
// 	;
// }

// void	p_quick_sort(t_data *data, t_list_node *list_head)
// {
// 	;
// }

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



// void	divide_in_three(t_data *data, t_list_node *list)
// {
// 	int	temp;
// 	int	metric[3];

// 	metric[0] = list->highest_val;
// 	metric[1] = list->child->highest_val;
// 	metric[2] = list->child->child->highest_val;
// 	// temp = *list->stack[previous(list->stack, 0)];
// 	temp = **list->stack;
// 	while (temp <= metric[1])
// 	{
// 		push_other(data, list->stack_name);
// 		if (temp <= metric[0] && *stack_from_name(data,
// 			opposite_name(list->stack_name)))
// 			rotate_other(data, list->stack_name, 1);
// 		temp = **list->stack;
// 	}
// 	rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
// 	while (**list->stack != temp)
// 	{
// 		if (**list->stack <= metric[0])
// 		{
// 			push_other(data, list->stack_name);
// 			rotate_other(data, list->stack_name, 1);
// 		}
// 		else if (**list->stack <= metric[1])
// 			push_other(data, list->stack_name);
// 		else
// 			rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
// 	}
// 	list->stack_name = opposite_name(list->stack_name);
// 	list->stack = stack_from_name(data, list->stack_name);
// 	list->child->stack_name = list->stack_name;
// 	list->child->stack = list->stack;
// }

bool	in_range(int min, int max, int num)
{
	return (num >= min && num <= max);
}

bool	in_2_ranges(int *range_1, int *range_2, int num)
{
	return (in_range(range_1[0], range_1[1], num)
		|| in_range(range_2[0], range_2[1], num));
}

void	get_metrics(int *metric, t_list_node *list)
{
	metric[0] = list->lowest_val;
	metric[1] = list->highest_val;
	if (list->child)
	{
		metric[2] = list->child->lowest_val;
		metric[3] = list->child->highest_val;
	}
	else
	{
		metric[2] = 0;
		metric[3] = 0;
	}
}

void	stack_update(t_list_node *list, t_data *data, char name)
{
	list->stack_name = name;
	list->stack = stack_from_name(data, name);
}

void divide_in_three(t_data *data, t_list_node *list)
{
	int temp;
	int metric[4];

	get_metrics(metric, list);
	temp = **list->stack;
	while (in_2_ranges(&metric[0], &metric[2], temp))
	{
		push_other(data, list->stack_name);
		if (in_range(metric[0], metric[1], temp) && *stack_from_name(data,
				opposite_name(list->stack_name)))
			rotate_other(data, list->stack_name, 1);
		temp = **list->stack;
	}
	rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
	while (**list->stack != temp)
	{
		if (in_range(metric[0], metric[1], **list->stack))
		{
			if (!list->stack[1] || (in_2_ranges(&metric[0], &metric[2],
						*list->stack[1]) || *list->stack[1] == temp))
			{
				push_other(data, list->stack_name);
				rotate_other(data, list->stack_name, 1);
			}
			else
			{
				push_other(data, list->stack_name);
				rotate_both(data->stack_a, data->stack_b, 1);
			}
		}
		else if (in_range(metric[2], metric[3], **list->stack))
			push_other(data, list->stack_name);
		else
			rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
	}
	stack_update(list, data, opposite_name(list->stack_name));
	stack_update(list->child, data, opposite_name(list->child->stack_name));
}

void divide_in_three_lis(t_data *data, t_list_node *list, int **lis)
{
	int temp;
	int metric[4];

	get_metrics(metric, list);
	temp = **list->stack;
	while (in_2_ranges(&metric[0], &metric[2], temp)
		&& !in(temp, lis[1], **lis))
	{
		push_other(data, list->stack_name);
		if (in_range(metric[0], metric[1], temp) && *stack_from_name(data,
				opposite_name(list->stack_name)))
			rotate_other(data, list->stack_name, 1);
		temp = **list->stack;
	}
	rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
	while (**list->stack != temp)
	{
		if (in_range(metric[0], metric[1], **list->stack)
			&& !in(**list->stack, lis[1], **lis))
		{
			if (!list->stack[1] || ((in_2_ranges(&metric[0], &metric[2], \
			*list->stack[1]) || *list->stack[1] == temp) \
			&& !in(*list->stack[1], lis[1], **lis)))
			{
				push_other(data, list->stack_name);
				rotate_other(data, list->stack_name, 1);
			}
			else
			{
				push_other(data, list->stack_name);
				rotate_both(data->stack_a, data->stack_b, 1);
			}
		}
		else if (in_range(metric[2], metric[3], **list->stack) \
		&& !in(**list->stack, lis[1], **lis))
			push_other(data, list->stack_name);
		else
			rotate_name(list->stack, 1, stack_len(list->stack), list->stack_name);
	}
	stack_update(list, data, opposite_name(list->stack_name));
	stack_update(list->child, data, opposite_name(list->child->stack_name));
}

int	list_len(t_list_node *head)
{
	t_list_node	*current;
	int			i;

	i = 0;
	current = head;
	while (current)
	{
		current = current->child;
		i++;
	}
	return (i);
}

t_list_node *get_est_node(t_list_node *head, int sign)
{
	t_list_node	*highest;

	highest = head;
	while (head->child)
	{
		head = head->child;
		if (head->highest_val * sign > highest->highest_val * sign)
			highest = head;
	}
	return (highest);
}

t_list_node *get_highest_node(t_list_node *head)
{
	return (get_est_node(head, 1));
}

t_list_node *get_lowest_node(t_list_node *head)
{
	return (get_est_node(head, -1));
}

t_list_node *set_first(t_list_node *head, t_list_node *node)
{
	if (node == head)
		return (head);
	node->parent->child = node->child;
	if (node->child)
		node->child->parent = node->parent;
	node->parent = NULL;
	head->parent = node;
	node->child = head;
	return (node);
}

t_list_node	*reverse_list(t_list_node *head)
{
	t_list_node *current;
	t_list_node *temp;

	head = set_first(head, get_n_child(head, -1));
	current = head;
	while (current->child)
	{
		temp = current;
		current = current->child;
		current = set_first(current, get_n_child(current, -1));
		current->parent = temp;
		temp->child = current;
	}
	return (head);
}

t_list_node	*sort_list(t_list_node *head, int len)
{
	int			i;
	t_list_node	*temp;
	t_list_node	*current;

	i = 1;
	head = set_first(head, get_lowest_node(head));
	current = head;
	while (current->child)
	{
		temp = current;
		current = current->child;
		if ((i & 1 && len & 1) || (!(i & 1) && !(len & 1)))
			current = set_first(current, get_highest_node(current));
		else
			current = set_first(current, get_lowest_node(current));
		current->parent = temp;
		temp->child = current;
		i++;
	}
	head = reverse_list(head);
	return (head);
}

void	divide_in_two(t_data *data, t_list_node *list)
{
	int		start;
	int		metric[4];
	int		**stack;
	char	name;

	name = list->stack_name;
	get_metrics(metric, list);
	stack = stack_from_name(data, name);
	start = **stack;
	while (*stack && in_range(metric[0], metric[1], start))
	{
		push_other(data, name);
		start = **stack;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		if (in_range(metric[0], metric[1], **stack))
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

void	divide_in_two_lis(t_data *data, t_list_node *list, int **lis)
{
	int	start;
	int	metric[4];
	int	**stack;
	char	name;

	name = list->stack_name;
	get_metrics(metric, list);
	stack = stack_from_name(data, name);
	start = **stack;
	while (*stack && in_range(metric[0], metric[1], start) \
	&& !in(start, lis[1], **lis))
	{
		push_other(data, name);
		start = **stack;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		if (in_range(metric[0], metric[1], **stack) \
		&& !in(**stack, lis[1], **lis))
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

void	last_group(t_data *data, t_list_node *current)
{
	if (list_len(current) == 2)
	{
		divide_in_two(data, current);
		stack_update(current, data, opposite_name(current->stack_name));
		current = current->child;
	}
	while (*current->stack)
	{
		push_name(stack_from_name(data, opposite_name(current->stack_name)),
			current->stack, opposite_name(current->stack_name));
		rotate_other(data, current->stack_name, 1);
	}
	stack_update(current, data, opposite_name(current->stack_name));
}

void	last_group_lis(t_data *data, t_list_node *current, int **lis)
{
	int	t;

	if (list_len(current) == 2)
		divide_in_three_lis(data, current, lis);
	t = 0;
	while (list_len(current) && (!t || !in(*data->stack_a[t], lis[1], **lis)))
		t = previous(data->stack_a, t);
	t = *data->stack_a[t];
	while (*data->stack_a && **data->stack_a != t)
	{
		if (!in(**current->stack, lis[1], **lis))
		{
			push_b(data->stack_b, data->stack_a);
			if ((!in(**data->stack_a, lis[1], **lis)) || **data->stack_a == t)
				rotate_other(data, 'a', 1);
			else
				rotate_both(data->stack_a, data->stack_b, 1);
		}
		else
			rotate_name(current->stack, 1, stack_len(current->stack), 'a');
	}
}

void	sync_rotate_to_goal_dist(t_data *data, int dist)
{
	int	dir;

	dir = sign(dist);
	while (dist)
	{
		rotate_both(data->stack_a, data->stack_b, dir);
		dist -= dir;
	}
}

void	syncronized_rotation_alt(t_data *data, int ta, int tb, int dir)
{
	int	target_val_a;
	int	target_val_b;
	int	shared_dist;
	int	temp;

	target_val_a = *data->stack_a[ta];
	target_val_b = *data->stack_b[tb];
	shared_dist = get_distance_sign(data->stack_a, 0, ta, -dir);
	temp = get_distance_sign(data->stack_b, 0, tb, -dir);
	if (ft_abs(shared_dist) > ft_abs(temp))
		shared_dist = temp;
	sync_rotate_to_goal_dist(data, shared_dist);
	rotate_to_goal(data->stack_a, find_of_value(data->stack_a, target_val_a), 0, 'a');
	rotate_to_goal(data->stack_b, find_of_value(data->stack_b, target_val_b), 0, 'b');
}

void	prepare_for_insertion(t_data *data, int *qp)
{
	int	target;
	int	goal;

	goal = adjacent_value_in_stack(data->stack_a, *data->stack_b[qp[2]], qp[3]);
	goal = next_n(data->stack_a, goal, (qp[3] < 0));
	target = qp[2];
	if (qp[1] == 0)
	{
		rotate_to_goal(data->stack_a, goal, 0, 'a');
		rotate_to_goal(data->stack_b, target, 0, 'b');
	}
	else
		syncronized_rotation_alt(data, goal, target, qp[1]);
}

void	insertion_sort(t_data *data)
{
	int	*qp;

	while (*data->stack_b && !is_sorted(data->stack_a, data->tot_len))
	{
		qp = quickest_pair(data, 'b');
		if (!qp)
			return ;
		prepare_for_insertion(data, qp);
		push_a(data->stack_a, data->stack_b);
		free(qp);
	}
	if (!*data->stack_b) 
		rotate_to_goal(data->stack_a, find_of_value(data->stack_a, 1), 0, 'a');
}

void	quick_sort_algo(t_data *data)
{
	t_list_node	*list_head;
	t_list_node	*current;
	int			n_chunks;
	int			**lis;

	list_head = list_init(data);
	if (!list_head)
		return ;
	lis = get_lis(data->stack_a, 0, data->tot_len);
	n_chunks = (data->tot_len > 5) + 2 * (data->tot_len > 50) + (data->tot_len > 99) + 3 * (data->tot_len > 299) + 3 * (data->tot_len > 499);
	if (!split_n_times(list_head, n_chunks))
	{
		free_all(data, list_head);
		return ;
	}
	list_head = sort_list(list_head, n_chunks);
	current = list_head;
	while (n_chunks > 2)
	{
		divide_in_three_lis(data, current, lis);
		current = current->child->child;
		n_chunks -= 2;
	}
	last_group_lis(data, current, lis);
	free_list(list_head);
	insertion_sort(data);
	if (lis)
	{
		if (lis[0])
			free(lis[0]);
		if (lis[1])
			free(lis[1]);
		free(lis);
	}
}

