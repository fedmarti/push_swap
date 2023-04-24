/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:06 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:47:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adjacent_n(int **stack, int index, int amount, int direction)
{
	while (amount--)
		index = adjacent(stack, index, direction);
	return (index);
}

int	next_n(int **stack, int index, int amount)
{
	return (adjacent_n(stack, index, amount, 1));
}

int	previous_n(int **stack, int index, int amount)
{
	return (adjacent_n(stack, index, amount, -1));
}

int	rotate_to_goal(int **stack, int target, int goal, char name)
{
	int	dir;
	int	dist;
	int	len;

	len = stack_len(stack);
	dist = get_distance(stack, target, goal);
	dir = sign(dist);
	while (dist)
	{
		rotate_name(stack, dir, len, name);
		dist -= dir;
	}
	return (0);
}
