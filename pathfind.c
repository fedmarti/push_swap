/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:02:16 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:50:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next(int **stack, int index)
{
	if (stack[index + 1])
		return (index + 1);
	return (0);
}

int	previous(int **stack, int index)
{
	int	len;

	if (index)
		return (index - 1);
	len = stack_len(stack);
	return (len - 1);
}

int	adjacent(int **stack, int index, int sign)
{
	if (sign > 0)
		return (next(stack, index));
	return (previous(stack, index));
}

int	get_direction(int **stack, int target, int goal)
{
	int	dir;

	dir = get_distance(stack, target, goal);
	return (sign(dir));
}

int	get_distance(int **stack, int target, int goal)
{
	int	distance;
	int	pac_man;
	int	sta_len;

	sta_len = stack_len(stack);
	distance = target - goal;
	if (goal > target)
		pac_man = sta_len - goal - target;
	else
		pac_man = -(sta_len - goal - target);
	return (abs_min_signed(distance, pac_man));
}

// int	get_distance(int **stack, int target, int goal)
// {
// 	int	distance;
// 	int	pac_man;
// 	int	sta_len;

// 	sta_len = stack_len(stack);
// 	distance = goal - target;
// 	if (goal > target)
// 		pac_man = -(sta_len - goal + target);
// 	else
// 		pac_man = sta_len + goal - target;
// 	if (ft_abs(distance) > ft_abs(pac_man))
// 		distance = pac_man;
// 	return (distance);
// }
