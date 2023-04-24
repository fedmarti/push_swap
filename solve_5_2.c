/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:45:17 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 17:52:37 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_targets(int *arr, int **lis, int **stack);
int		**get_longest_lis(t_data *data);

int	**norminette_bullshit(int **lis, t_data *data, int *targets, int j)
{
	rotate_to_goal(data->stack_a, targets[j], 0, 'a');
	push_b(data->stack_b, data->stack_a);
	free_lis(lis);
	lis = get_longest_lis(data);
	get_targets(targets, lis, data->stack_a);
	return (lis);
}

void	norm_bs_2(t_data *data, int **lis)
{
	if (previous_value_in_stack(data->stack_a, **data->stack_a) == 1)
		swap_a(data->stack_a);
	if (*data->stack_b)
		insertion_sort(data);
	if (**lis == data->tot_len)
		rotate_to_goal(data->stack_a, find_lowest(data->stack_a), 0, 'a');
	free_lis(lis);
}
