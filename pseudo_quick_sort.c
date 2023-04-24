/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:28:36 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pseudo_quick_sort.h"

void	divide_in_three_lis(t_data *data, t_list_node *list, int **lis)
{
	int	start;
	int	metric[4];

	start = prep_4_div(data, list, lis, metric);
	while (**list->stack != start)
	{
		if (in_range(metric[0], metric[1], **list->stack)
			&& !in(**list->stack, lis[1], **lis))
		{
			push_other(data, list->stack_name);
			if (div_check_2(list, lis, metric, start))
				rotate_other(data, list->stack_name, 1);
			else
				rotate_both(data->stack_a, data->stack_b, 1);
		}
		else if (in_range(metric[2], metric[3], **list->stack) \
		&& !in(**list->stack, lis[1], **lis))
			push_other(data, list->stack_name);
		else
			rotate_name(list->stack, 1, stack_len(list->stack), \
			list->stack_name);
	}
	stack_update(list, data, opposite_name(list->stack_name));
	stack_update(list->child, data, opposite_name(list->child->stack_name));
}

void	divide_in_two_lis(t_data *data, t_list_node *list, int **lis)
{
	int		start;
	int		metric[4];
	int		**stack;
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

void	last_group_lis(t_data *data, t_list_node *current, int **lis)
{
	int	t;

	if (list_len(current) == 2)
		divide_in_three_lis(data, current, lis);
	t = prepare_for_division_no_metric(data, lis);
	while (*data->stack_a && **data->stack_a != t)
	{
		if (!in(**data->stack_a, lis[1], **lis))
		{
			push_b(data->stack_b, data->stack_a);
			if ((!in(**data->stack_a, lis[1], **lis)) || **data->stack_a == t)
				rotate_b(data->stack_b, 1);
			else
				rotate_both(data->stack_a, data->stack_b, 1);
		}
		else
			rotate_a(data->stack_a, 1);
	}
}

int	get_n_chunks(int len)
{
	int	n_chunks;

	n_chunks = (len > 5);
	n_chunks += 2 * (len > 50);
	n_chunks += (len > 99);
	n_chunks += 3 * (len > 299);
	n_chunks += 3 * (len > 499);
	return (n_chunks);
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
	n_chunks = get_n_chunks(data->tot_len);
	if (!split_n_times(list_head, n_chunks))
		return ((void)free_data_list(data, list_head));
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
	free_lis(lis);
}
