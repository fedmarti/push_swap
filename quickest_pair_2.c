/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickest_pair_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:26:03 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:55:14 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*dist_check(int *dist, int dist_2, int flag)
{
	if (ft_abs(dist_2) < ft_abs(dist[0]))
	{
		dist[0] = dist_2;
		dist[1] = flag;
	}
	return (dist);
}
//calculates lowest number of moves to push target into stack of goal
//goal depends on sign 1: first value higher than target in other stack 
// -1 : first value lower than target in other stack)
//goals goal is the place you should rotate goal to push target into the stack
//so it's 0 if goal is bigger than targer, and previous(0), if it's smaller

int	*moves_to_push(int **src_stack, int **dest_stack, int target, int sign)
{
	int	*dist;
	int	temp;
	int	goal;

	dist = malloc(4 * sizeof(int));
	if (!dist)
		return (NULL);
	goal = adjacent_value_in_stack(dest_stack, *src_stack[target], sign);
	goal = next_n(dest_stack, goal, (sign < 0));
	dist[0] = abs_max(get_distance_sign(src_stack, target, 0, 1),
			get_distance_sign(dest_stack, goal, 0, 1));
	dist[1] = 1;
	temp = abs_max(get_distance_sign(src_stack, target, 0, -1),
			get_distance_sign(dest_stack, goal, 0, -1));
	dist = dist_check(dist, temp, -1);
	temp = get_direction(dest_stack, goal, 0);
	if (temp != get_direction(src_stack, target, 0))
	{
		temp = abs(get_distance(dest_stack, goal, 0)) + abs(
				get_distance(src_stack, target, 0));
		dist = dist_check(dist, temp, 0);
	}
	dist[2] = target;
	dist[3] = sign;
	return (dist);
}

// int	*moves_to_push(int **src_stack, int **dest_stack, int target, int sign)
// {
// 	int	*dist;
// 	int	temp;
// 	int	goal;
// 	int	goals_goal;

// 	dist = malloc(4 * sizeof(int));
// 	if (!dist)
// 		return (NULL);
// 	goal = adjacent_value_in_stack(dest_stack, *src_stack[target], sign);
// 	goals_goal = previous_n(dest_stack, 0, (sign < 0));
// 	dist[0] = abs_max(get_distance_sign(src_stack, target, 0, 1),
// 			get_distance_sign(dest_stack, goal, goals_goal, 1));
// 	dist[1] = 1;
// 	temp = abs_max(get_distance_sign(src_stack, target, 0, -1),
// 			get_distance_sign(dest_stack, goal, goals_goal, -1));
// 	dist = dist_check(dist, temp, -1);
// 	temp = get_direction(dest_stack, goal, goals_goal);
// 	if (temp != get_direction(src_stack, target, 0))
// 		temp = abs(get_distance(dest_stack, goal, goals_goal)) + abs(
// 				get_distance(src_stack, target, goal));
// 	dist = dist_check(dist, temp, 0);
// 	dist[2] = target;
// 	dist[3] = sign;
// 	return (dist);
// }
//0 = abs_distance, 1 = direction, 2 = target, 3 = sign
