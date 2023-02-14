/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//divide in sequences of 2/3

//sort them

//compare two adjacent sequences

//higheset gets rotated, lowest gets pushed, when it's finished push all of b
// keep track of the first and last node of the sequence


/*
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


void	merge_2(int **main, int **secondary, char name)
{
	int	dir;

	if (name == 'a')
		dir = 1;
	else 
		dir == -1;
	if (**main * dir > *main[1] * dir)
		swap_name(main, name);
} */

int ii = 0;

void	merge_2(int **stack, int size)
{
	if (stack[1])
	{
		if (*stack[0] > *stack[1] && size == 2)
			swap_a(stack);
	}
}

bool	is_sequence_sorted(int **stack, int len, int sign)
{
	int	i;

	i = 1;
	while (stack[i - 1] && stack[i] && len > 1)
	{
		if (*stack[i - 1] * sign > *stack[i] * sign)
			return (false);
		i++;
		len--;
	}
	return (true);
}

int	store_est_in_stack(int **main, int **secondary, int dir, int size)
{
	int	i;

	i = 0;
	while (*main && *secondary && size--)
	{
		if (**main * dir < **secondary * dir)
		{
			push_name(main, secondary, 'a' + (-sign(dir - 1)));
			i++;
		}
	}
	return (i);		 
}

int	store_highest_in_a(t_data *data, int size)
{
	return(store_est_in_stack(data->stack_a, data->stack_b, 1, size));
}

int	store_lowest_in_b(t_data *data, int size)
{
	return (store_est_in_stack(data->stack_b, data->stack_a, -1, size));
}



int	prepare_for_merge_b(t_data *data, int size)
{
	int target_a;
	int	target_b;
	int	dist_a;
	int	dist_b;

	target_a = find_lowest_size(data->stack_a, size);
	target_b = find_lowest_size(data->stack_b, size);
	if (*data->stack_b[target_b] > *data->stack_a[target_a])
		target_b = previous(data->stack_b, target_b);
	dist_a = get_distance(data->stack_a, 0, target_a);
	dist_b = get_distance(data->stack_b, 0, target_b);

	if (abs(dist_a) + abs(dist_b) < min(abs(dist_a), abs(dist_b)) 
		+ abs(get_distance(data->stack_a, target_a, target_b)))
	{
		rotate_to_goal_flag(data, 0, target_a, 1);
		rotate_to_goal_flag(data, 0, target_b, -2);
	}
	else
		syncronized_rotation (data, target_a, target_b);
	return (store_lowest_in_b(data, size));
}

int	prepare_for_merge_a(t_data *data, int size)
{
	int target_a;
	int	target_b;
	int	dist_a;
	int	dist_b;

	target_a = find_highest_size(data->stack_a, size);
	target_b = find_highest_size(data->stack_b, size);
	if (*data->stack_a[target_a] < *data->stack_b[target_b])
		target_a = next(data->stack_a, target_a);
	dist_a = get_distance(data->stack_a, 0, target_a);
	dist_b = get_distance(data->stack_b, 0, target_b);

	if (abs(dist_a) + abs(dist_b) < min(abs(dist_a), abs(dist_b)) 
		+ abs(get_distance(data->stack_a, target_a, target_b)))
	{
		rotate_to_goal_flag(data, 0, target_a, 1);
		rotate_to_goal_flag(data, 0, target_b, -2);
	}
	else
		syncronized_rotation (data, target_a, target_b);
	return (store_highest_in_a(data, size));
}

bool	merge_backtrack_check(int **main_s, int **secondary, int main_len, int dir)
{
	int	last_val;

	(void) dir;
	if (main_len <= 1)
		return (true);
	last_val = *main_s[previous(main_s, 0)];
	if (**secondary > last_val)
		return (true);
	if (**main_s < last_val)
		return (true);
	return (false);

}

void	merge_size(int **main_s, int **secondary, int size, int dir)
{
	int		main_len;
	char	name_main;

	name_main = 'a' + (-sign(dir - 1));
	main_len = stack_len(main_s);
	while (size > 0)
	{
		if (!*main_s)
		{
			push_name(main_s, secondary, name_main);
			main_len++;
			size--;
		}
		else if (*secondary)
		{
			if (**main_s * dir > **secondary * dir 
			&& merge_backtrack_check(main_s, secondary, main_len, dir))
			{
				push_name(main_s, secondary, name_main);
				main_len++;
				size--;
			}
			else
				rotate_name(main_s, -1, main_len, name_main);
		}
		else
		{
			rotate_name(main_s, -1, main_len, name_main);
			size--;
		}
	}
}

void	merge_a(t_data *data, int size)
{
	merge_size(data->stack_a, data->stack_b, size, 1);
}


void	merge_b(t_data *data, int size)
{
	merge_size(data->stack_b, data->stack_a, size, -1);
}

void	repeat_push(int **main, int **secondary, void (*f)(int**,int**), int times)
{
	while (times)
	{
		f(main, secondary);
		times--;
	}
}

void	merge(t_data *data, int size, int parent_size, int child_num)
{
	ii++;
	if (ii > 20)
		return ;
	int temp;	
	if (is_sequence_sorted(data->stack_a, size, 1))
	{
		if (size == data->tot_len)
			return ;
		if (stack_len(data->stack_b) <= size)
			merge_b(data, size);
		else
		{
			if (child_num == 2)
			{
				temp =  prepare_for_merge_a(data, size);
				merge_a(data, parent_size - size - temp);
				temp = find_lowest_size(data->stack_a, parent_size);
				rotate_to_goal_flag(data, temp, 0, 1);
			//	merge(data, parent_size, parent_size * 2, 2);
			}
			else
				repeat_push(data->stack_b, data->stack_a, push_b, size);
		}
	}
	else
	{
		if (size <= 2)
			merge_2(data->stack_a, size);
		else
		{
			merge(data, size / 2, size, 1);
			merge(data, size - (size / 2), size, 2);
		}
		merge(data, size, parent_size, child_num);

	}
}
/*
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
*/
void	merge_sort(t_data *data)
{
	merge(data, data->tot_len, 0, 1);
}
