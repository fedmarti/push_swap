/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:27:24 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:28:10 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_quick_sort.h"

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

int	prep_4_div(t_data *data, t_list_node *node, int **lis, int *met)
{
	int	temp;

	get_metrics(met, node);
	temp = **node->stack;
	while (in_2_ranges(&met[0], &met[2], temp)
		&& !in(temp, lis[1], **lis))
	{
		push_other(data, node->stack_name);
		if (in_range(met[0], met[1], temp) && *stack_from_name(data,
				opposite_name(node->stack_name)))
			rotate_other(data, node->stack_name, 1);
		temp = **node->stack;
	}
	rotate_name(node->stack, 1, stack_len(node->stack), node->stack_name);
	return (temp);
}

bool	div_check_2(t_list_node *list, int **lis, int *metric, int start)
{
	bool	in_lis;
	bool	in_range_1_or_2;
	bool	to_b_pushed;
	bool	is_start;

	if (!list->stack[0])
		return (true);
	in_range_1_or_2 = in_2_ranges(&metric[0], &metric[2], *list->stack[0]);
	in_lis = in(*list->stack[0], lis[1], **lis);
	is_start = (*list->stack[0] == start);
	to_b_pushed = (in_range_1_or_2 && !in_lis);
	return (to_b_pushed || is_start);
}

int	prepare_for_division_no_metric(t_data *data, int **lis)
{
	int	temp;

	temp = **data->stack_a;
	while (!in(temp, lis[1], **lis))
	{
		push_b(data->stack_b, data->stack_a);
		temp = **data->stack_a;
	}
	rotate_a(data->stack_a, 1);
	return (temp);
}
