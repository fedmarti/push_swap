/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barista_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:25:30 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/07 18:18:06 by fedmarti         ###   ########.fr       */
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

	if ft_abs(dist_a) + ft_abs(dist_b) < ft_min(ft_abs(dist_a), ft_abs(dist_b)) 
		+ ft_abs(get_distance(data->stack_a, target_a, highest_b)))
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