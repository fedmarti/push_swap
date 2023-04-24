/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:25:09 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:26:23 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sync_rotate_to_goal_dist(t_data *data, int dist)
{
	int	dir;

	dir = sign(dist);
	while (dist)
	{
		rotate_both(data->stack_a, data->stack_b, dir);
		dist -= dir;
	}
}

void	syncronized_rotation_alt(t_data *data, int ta, int tb, int dir)
{
	int	target_val_a;
	int	target_val_b;
	int	shared_dist;
	int	temp;

	target_val_a = *data->stack_a[ta];
	target_val_b = *data->stack_b[tb];
	shared_dist = get_distance_sign(data->stack_a, 0, ta, -dir);
	temp = get_distance_sign(data->stack_b, 0, tb, -dir);
	if (ft_abs(shared_dist) > ft_abs(temp))
		shared_dist = temp;
	sync_rotate_to_goal_dist(data, shared_dist);
	rotate_to_goal(data->stack_a, \
	find_of_value(data->stack_a, target_val_a), 0, 'a');
	rotate_to_goal(data->stack_b, \
	find_of_value(data->stack_b, target_val_b), 0, 'b');
}

void	prepare_for_insertion(t_data *data, int *qp)
{
	int	target;
	int	goal;

	goal = adjacent_value_in_stack(data->stack_a, *data->stack_b[qp[2]], qp[3]);
	goal = next_n(data->stack_a, goal, (qp[3] < 0));
	target = qp[2];
	if (qp[1] == 0)
	{
		rotate_to_goal(data->stack_a, goal, 0, 'a');
		rotate_to_goal(data->stack_b, target, 0, 'b');
	}
	else
		syncronized_rotation_alt(data, goal, target, qp[1]);
}

void	insertion_sort(t_data *data)
{
	int	*qp;

	while (*data->stack_b && !is_sorted(data->stack_a, data->tot_len))
	{
		qp = quickest_pair(data, 'b');
		if (!qp)
			return ;
		prepare_for_insertion(data, qp);
		push_a(data->stack_a, data->stack_b);
		free(qp);
	}
	if (!*data->stack_b)
		rotate_to_goal(data->stack_a, find_of_value(data->stack_a, 1), 0, 'a');
}
