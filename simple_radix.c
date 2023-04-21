/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/03/30 20:23:45 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_in_two_neg(t_data *data, int **stack, char name, int sig_digit)
{
	int	start;

	if (sig_digit > data->tot_len * 2)
		return ;
	start = **stack;
	while (start & sig_digit)
	{
		push_other(data, name);
		start = **stack;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		if (**stack & sig_digit)
			push_other(data, name);
		else
			rotate_name(stack, 1, stack_len(stack), name);
	}
}

static void	divide_in_two(t_data *data, int **stack, char name, int sig_digit)
{
	int	start;

	if (sig_digit > data->tot_len * 2)
		return ;
	start = **stack;
	while (!(start & sig_digit))
	{
		push_other(data, name);
		start = **stack;
	}
	rotate_name(stack, 1, stack_len(stack), name);
	while (**stack != start)
	{
		if (**stack & sig_digit)
			rotate_name(stack, 1, stack_len(stack), name);
		else
			push_other(data, name);
	}
}

void	simple_radix(t_data *data)
{
	char	name;
	int		metric;

	metric = 1;
	name = 'a';
	while (metric <= data->tot_len
		&& !(is_sorted(data->stack_a, data->tot_len)))
	{
		if (name == 'a')
			divide_in_two(data, data->stack_a, name, metric);
		else
			divide_in_two_neg(data, data->stack_b, name, metric);
		while (*stack_from_name(data, name))
			push_other(data, name);
		name = opposite_name(name);
		metric = metric << 1;
	}
}
