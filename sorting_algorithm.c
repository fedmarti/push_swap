/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:59:06 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 21:59:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include "push_swap.h"

static int find_lowest(int **stack)
{
	int	i;
	int	lowest;

	i = 1;
	lowest = 0;
	while(stack[i])
	{
		if (*(stack[lowest]) > *(stack[i]))
			lowest = i;
		i++;
	}
	return (lowest);
}

void	move_to_first(int **stack_a, int **stack_b, int i)
{
	int	lowest;
	int	dir;
	int	r;

	r = 0;
	lowest = find_lowest(&(stack_a[i]));
	while (r < i)
	{
		push_b(stack_b, stack_a);
		r++;
	}
	if (lowest <= stack_len(stack_a) / 2)
		dir = 1;
	else
	{
		dir = -1;
		lowest = stack_len(stack_a) - lowest;
	}
	r = 0;
	while (r < lowest)
	{
		rotate_a(stack_a, dir);
		r++;
	}
	r = 0;
	while (r < i)
	{
		push_a(stack_a, stack_b);
		r++;
	}
}

bool	is_sorted(int **stack, int len)
{
	bool	sorted;
	int		i;

	i = 0;
	sorted = true;
	if (stack_len(stack) < len)
		return (false);
	while(i < len && sorted)
	{
		if (find_lowest(&(stack[i])) != 0)
			sorted = false;
		i++;
	}
	return (sorted);
}

void	sorting_algorithm(int **stack_a, int **stack_b)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(stack_a);
	while (!is_sorted(stack_a, len))
	{
		move_to_first(stack_a, stack_b, i);
		i++;
	}
}