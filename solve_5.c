/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:45:17 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/22 00:29:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lis(int **lis)
{
	if (lis[0])
	{
		free(lis[0]);
		lis[0] = NULL;
	}
	if (lis[1])
	{
		free(lis[1]);
		lis[1] = NULL;
	}
	if (lis)
	{
		free(lis);
		lis = NULL;
	}
}

int	**get_longest_lis(t_data *data)
{
	int	**lis;
	int	**temp;
	int	i;
	int	len;

	i = 1;
	len = stack_len(data->stack_a);
	lis = get_lis(data->stack_a, 0, len);
	if (!lis)
		return (NULL);
	while (i < len && **lis < len)
	{
		temp = get_lis(data->stack_a, i, len);
		if (!temp || **temp > **lis)
		{
			free_lis(lis);
			lis = temp;
		}
		else
			free_lis(temp);
		if (!lis)
			return (NULL);
		i++;
	}
	return (lis);
}

void	get_targets(int *arr, int **lis, int **stack)
{
	int	i;
	int	j;
	int	len;

	len = stack_len(stack);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (!in(*stack[i], lis[1], **lis))
		{
			arr[j] = i;
			j++;
		}
		i++;
	}
	while (j < len)
	{
		arr[j] = -1;
		j++;
	}
}




void	solve_5(t_data *data)
{
	int	**lis;
	int	targets[5];
	int	i;
	int	j;

	lis = get_longest_lis(data);
	// lis = get_lis(data->stack_a, 0, data->tot_len);
	if (!lis)
		return ;
	get_targets(targets, lis, data->stack_a);
	i = 0;
	while (targets[i] != -1 && stack_len(data->stack_a) > 3)
	{
		j = 0;
		while (targets[i] != -1)
		{
			if (ft_abs(get_distance(data->stack_a, targets[j], 0))> ft_abs(get_distance(data->stack_a, targets[i], 0)))
				j = i ;
			i++;
		}
		rotate_to_goal(data->stack_a, targets[j], 0, 'a');
		push_b(data->stack_b, data->stack_a);
		free(lis);
		i = 0;
		lis = get_longest_lis(data);
		get_targets(targets, lis, data->stack_a);
	}
	if (previous_value_in_stack(data->stack_a, **data->stack_a) == 1)
		swap_a(data->stack_a);
	if (*data->stack_b)
		insertion_sort(data);
	if (**lis == data->tot_len)
		rotate_to_goal(data->stack_a, find_lowest(data->stack_a), 0, 'a');
	free_lis(lis);

}
