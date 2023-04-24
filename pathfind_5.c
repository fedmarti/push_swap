/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:58:42 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:49:40 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sequence_extreme(int **stack, int index, int direction)
{
	int	adjacent_i;

	adjacent_i = adjacent(stack, index, direction);
	while (adjacent_i == adjacent_value_in_stack(stack, index, direction))
	{
		index = adjacent_i;
		adjacent_i = adjacent(stack, index, direction);
	}
	return (index);
}

int	get_sequence_head(int **stack, int index)
{
	return (get_sequence_extreme(stack, index, -1));
}

int	get_sequence_tail(int **stack, int index)
{
	return (get_sequence_extreme(stack, index, 1));
}

int	find_highest_size(int **stack, int size)
{
	return (find_est_sign_based_size(stack, 1, size));
}

int	get_distance_sign(int **stack, int target, int goal, int sign)
{
	int	i;
	int	current;

	current = target;
	i = 0;
	while (current != goal)
	{
		current = adjacent(stack, current, sign);
		i += sign;
	}
	return (i);
}
