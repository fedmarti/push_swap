/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:57:54 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/03 22:34:03 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if called with positive sign returns the index of the highest
//  if negative it's the lowest

int	find_est_sign_based(int **stack, int sign)
{
	int	i;
	int	est;

	i = 1;
	est = 0;
	while (stack[i])
	{
		if (*(stack[est]) * sign < *(stack[i]) * sign)
			est = i;
		i++;
	}
	return (est);
}

int	find_lowest(int **stack)
{
	return (find_est_sign_based(stack, -1));
}

int	find_highest(int **stack)
{
	return (find_est_sign_based(stack, 1));
}
/*
int	rotate_to_goal(int **stack, int target, int goal)
{
	int	dir;

	dir = get_direction(stack, target, 0);
	if (dir)
	{
		rotate_a(stack, dir);
		return (0);
	}
	return (1);
}

int	get_sequence_length(int **stack, int index, int direction)
{
	int	i;
	int	next;

	i = 0;
	next = adjacent(stack, index, direction);
	while (next == next_value_in_stack(stack, *(stack[index])))
	{
		index = next;
		next = adjacent(stack, index, direction);
		i++;
	}
	return (i);
}
*/