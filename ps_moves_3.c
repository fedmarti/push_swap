/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:11:03 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:50:50 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_move(char move, int stack, int dir)
{
	if (!stack)
		return ;
	if (move == 'r' && dir == -1)
		write(1, "r", 1);
	write(1, &move, 1);
	if (stack == 1)
		write(1, "a", 1);
	else if (stack == 2)
		write (1, "b", 1);
	else if (stack == 3)
		write(1, &move, 1);
	write(1, "\n", 1);
}

void	rotate_to_goal_flag(t_data *data, int target, int goal, int flag)
{
	int	dir;
	int	distance;
	int	**stack;

	if (flag > 0)
		stack = data->stack_a;
	else
		stack = data->stack_b;
	distance = get_distance(stack, goal, target);
	dir = sign(distance);
	if (dir)
	{
		while (distance)
		{
			if (ft_abs(flag) != 2)
				rotate_stack(data->stack_a, dir, stack_len(data->stack_a));
			if (ft_abs(flag) != 1)
				rotate_stack(data->stack_b, dir, stack_len(data->stack_b));
			print_move('r', ft_abs(flag), dir);
			distance -= dir;
		}
	}
}

void	syncronized_rotation(t_data *data, int target_a, int target_b)
{
	int	flag;
	int	goal;
	int	first_stretch;
	int	target_val;
	int	dist_b;

	target_val = *data->stack_a[target_a];
	first_stretch = ft_abs(get_distance(data->stack_a, 0, target_a));
	dist_b = ft_abs(get_distance(data->stack_b, 0, target_a));
	goal = target_a;
	flag = 3;
	if (first_stretch > dist_b)
	{
		flag *= -1;
		goal = target_b;
		first_stretch = dist_b;
	}
	rotate_to_goal_flag(data, goal, 0, flag);
	rotate_to_goal_flag(data, find_of_value(data->stack_a, target_val), 0, 1);
	rotate_to_goal_flag(data, find_highest(data->stack_b), 0, -2);
}
