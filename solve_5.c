/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:45:17 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 17:53:01 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_bs_2(t_data *data, int **lis);
int		**norminette_bullshit(int **lis, t_data *data, int *targets, int j);

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

	i = 0;
	len = stack_len(data->stack_a);
	lis = get_lis(data->stack_a, 0, len);
	if (!lis)
		return (NULL);
	while (i++ < len)
	{
		temp = get_lis(data->stack_a, 0, len);
		if (!temp || **temp > **lis)
		{
			free_lis(lis);
			lis = temp;
		}
		else
			free_lis(temp);
		if (!lis)
			return (NULL);
		rotate_stack(data->stack_a, 1, len);
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
	if (!lis)
		return ;
	get_targets(targets, lis, data->stack_a);
	i = 0;
	while (targets[i] != -1 && stack_len(data->stack_a) > 3)
	{
		j = 0;
		while (targets[i] != -1)
		{
			if (ft_abs(get_distance(data->stack_a, targets[j], 0)) \
			> ft_abs(get_distance(data->stack_a, targets[i], 0)))
				j = i ;
			i++;
		}
		i = 0;
		lis = norminette_bullshit(lis, data, targets, j);
	}
	norm_bs_2(data, lis);
}
