/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/02 06:50:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//divide in sequences of 2/3

//sort them

//compare two adjacent sequences

//higheset gets rotated, lowest gets pushed, when it's finished push all of b
// keep track of the first and last node of the sequence

int	get_distance_dir(int **stack, int target, int goal, int dir)
{
	int	distance;

	distance = 0;
	while (target != goal)
	{
		target = adjacent(stack, target, dir);
		distance ++;
	}
	return (distance);
}

int	get_intermediate(int **stack, int start, int end)
{
	int	pivot;
	int	dis;

	dis = end - start;
	if (dis > 3)
		return (start + (dis - dis / 2));
	return (0);
}


int	first_step(t_data *data)
{
	push_b(data->stack_b, data->stack_a);
	push_b(data->stack_b, data->stack_a);
	push_b(data->stack_b, data->stack_a);
	solve_3(data->stack_b, data->stack_a, 'b');
	push_a(data->stack_a, data->stack_b);
	push_a(data->stack_a, data->stack_b);
	push_a(data->stack_a, data->stack_b);
	rotate_a(data->stack_a, 1);
	rotate_a(data->stack_a, 1);
	rotate_a(data->stack_a, 1);
	return (3);
}

void	merge_phase_one(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->tot_len)
	{
		if (data->tot_len & 1)
			i += first_step(data);
		if (**data->stack_a > *data->stack_a[1])
			swap_a(data->stack_a);
		rotate_a(data->stack_a, 1);
		rotate_a(data->stack_a, 1);
		i += 2;
	}

}

void	merge_next_phase(t_data *data, int sg_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < sg_size * 2)
	{
		if (**data->stack_a < *data->stack_a[sg_size - 1])
			
	}
}

void	merge_sort(t_data *data)
{
	int	subgroup_size;

	subgroup_size = 4;
	merge_phase_one(data);
	merge_next_phase(data, subgroup_size);
}
