/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:45:37 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/03 23:11:23 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

bool	is_sorted(int **stack, int len)
{
	bool	sorted;
	int		i;

	i = 0;
	sorted = true;
	if (stack_len(stack) < len)
		return (false);
	while (i < len && sorted)
	{
		if (find_lowest(&(stack[i])) != 0)
			sorted = false;
		i++;
	}
	return (sorted);
}

int	sign(int a)
{
	if (a < 0)
		return (-1);
	if (a == 0)
		return (0);
	return (1);
}

int	min(int a, int b)
{
	return ((a * (a < b)) + (b * (a > b)));
}

int	max(int a, int b)
{
	return ((a * (a > b)) + (b * (a < b)));
}