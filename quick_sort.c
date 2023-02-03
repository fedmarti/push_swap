/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:33:42 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/01 23:33:45 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	quick_sort_phase_1(t_data *data)
{

}
*/

void	quick_sort_mini_b(t_data *data)
{
	int		len;
	bool	check;
	int		pivot;

	len = stack_len(data->stack_b) / 2;
	while (data->stack_b[1])
	{
		pivot = *data->stack_b[len / 2];
		check = false;
		while (**data->stack_b != pivot || !check)
		{
			if (**data->stack_b > pivot)
				push_a(data->stack_a, data->stack_b);
			else if (**data->stack_b < pivot)
				rotate_b(data->stack_b, 1);
			else
			{
				check = true;
				rotate_b(data->stack_b, 1);
			}
		}
		len = stack_len(data->stack_b);
	}
}

#include <stdlib.h>

void	quick_sort(t_data *data)
{
	int		pivot;
	bool	check;
	int		len;

	len = data->tot_len;
	while (data->stack_a[1])
	{
		pivot = *data->stack_a[len / 2];
		check = false;
		while (**data->stack_a != pivot || !check)
		{
			if (**data->stack_a < pivot)
				push_b(data->stack_b, data->stack_a);
			else if (**data->stack_a > pivot)
				rotate_a(data->stack_a, 1);
			else
			{
				check = true;
				rotate_a(data->stack_a, 1);
			}
		}
		len = stack_len(data->stack_a);
	}

	len = stack_len(data->stack_b) / 2;
	while (data->stack_b[1])
	{
		pivot = *data->stack_b[len / 2];
		check = false;
		while (**data->stack_b != pivot || !check)
		{
			if (**data->stack_b > pivot)
				push_a(data->stack_a, data->stack_b);
			else if (**data->stack_b < pivot)
				rotate_b(data->stack_b, 1);
			else
			{
				check = true;
				rotate_b(data->stack_b, 1);
			}
		}
		len = stack_len(data->stack_b);
	}
}


