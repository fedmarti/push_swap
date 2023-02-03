/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:59:57 by fedmarti          #+#    #+#             */
/*   Updated: 2023/01/31 19:15:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_data *data)
{
	while (*data->stack_b)
	{
		push_a(data->stack_a, data->stack_b);
	}
}

bool	base_2_radix_sort(t_data *data)
{
	int			i;
	static int	significant_digit;
	static int	highest;

	if (!highest)
		highest = *data->stack_a[find_highest(data->stack_a)];
	if (!significant_digit)
		significant_digit = 1;
	else if (significant_digit * 2 < highest)
		significant_digit *= 2;
	else
		return (true);
	i = 0;
	while (i < data->tot_len)
	{
		if (**data->stack_a & significant_digit)
			rotate_a(data->stack_a, 1);
		else
			push_b(data->stack_b, data->stack_a);
		i++;
	}
	return (false);
}

void	sorting_algorithm(t_data *data)
{
	bool	sorted;

	sorted = false;
	while (!sorted)
	{
		sorted = base_2_radix_sort(data);
		push_back(data);
	}
}
