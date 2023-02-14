/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barista_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:25:30 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/07 16:24:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_data *data)
{
	int	i;
	int	goal;

	i = 0;
	goal = data->tot_len / 2;
	while (i < goal)
	{
		push_b(data->stack_b, data->stack_a);
		i++;
	}
}

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

void	bubble_sort_dir(t_data *data, int dir, int goal)
{
	int	i;
	int	flag;

	i = 0;
	while (i < goal)
	{
		flag = 0;
		if (**data->stack_a > *data->stack_a[1])
		{
			flag += 1;
			swap_stack(data->stack_a);
		}
		if (data->stack_b[1] && data->stack_b[i])
		{
			if (**data->stack_b < *data->stack_b[1])
			{
				flag += 2;
				swap_stack(data->stack_b);
			}
		}
		print_move('s', flag, 0);
		if (data->stack_b[i + 1])
			rotate_both(data->stack_a, data->stack_b, dir);
		else if (data->stack_a[i + 1])
			rotate_a(data->stack_a, dir);
		i++;
	}
}
/*
void	double_cocktail_sort(t_data *data)
{
	int	goal;

	goal = data->tot_len - (data->tot_len / 2);
	while (goal)
	{
		bubble_sort_dir(data, 1 - ((goal % 2) * 2), goal);
		goal--;
	}
}

void	merge(t_data *data)
{
	int	i;
	i = data->tot_len - 1;
	while (i--)
	{
		if (*data->stack_b)
		{
		 	if (**data->stack_a == **data->stack_b + 1)
				push_a(data->stack_a, data->stack_b);
			else
				rotate_a(data->stack_a, -1);
		}
		else
			rotate_a(data->stack_a, -1);
	}

}*/

void rotate_to_goal_flag(t_data *data, int target, int goal, int flag)
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
			if (abs(flag) != 2)
				rotate_stack(data->stack_a, dir, stack_len(data->stack_a));
			if (abs(flag) != 1)
				rotate_stack(data->stack_b, dir, stack_len(data->stack_b));
			print_move('r', abs(flag), dir);
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
	first_stretch = abs(get_distance(data->stack_a, 0, target_a));
	dist_b = abs(get_distance(data->stack_b, 0, target_a));
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
/*
void	store_highest_in_a(t_data *data)
{
	while (**data->stack_a < **data->stack_b)
		push_a(data->stack_a, data->stack_b);
}

void	prepare_for_merge(t_data *data)
{
	int target_a;
	int	highest_b;
	int	dist_a;
	int	dist_b;

	target_a = find_highest(data->stack_a);
	highest_b = find_highest(data->stack_b);
	if (*data->stack_a[target_a] < *data->stack_b[highest_b])
		target_a = next(data->stack_a, target_a);
	dist_a = get_distance(data->stack_a, 0, target_a);
	dist_b = get_distance(data->stack_b, 0, highest_b);

	if (abs(dist_a) + abs(dist_b) < min(abs(dist_a), abs(dist_b)) 
		+ abs(get_distance(data->stack_a, target_a, highest_b)))
	{
		rotate_to_goal_flag(data, 0, target_a, 1);
		rotate_to_goal_flag(data, 0, highest_b, -2);
	}
	else
		syncronized_rotation (data, target_a, highest_b);
	store_highest_in_a(data);
}

void	barista_sort(t_data *data)
{
	split_stack(data);
	double_cocktail_sort(data);
	prepare_for_merge(data);
	merge(data);
}*/