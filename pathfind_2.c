/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:50:47 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:36:07 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_junk_length(int **stack, int target, int direction)
{
	int	next;
	int	goal;
	int	i;

	next = adjacent(stack, target, direction);
	goal = adjacent_value_in_stack(stack, *(stack[target]), direction);
	i = 0;
	while (next != goal)
	{
		next = adjacent(stack, target, direction);
		i++;
	}
	return (i);
}

int	adjacent_value_in_stack(int **stack, int value, int sign)
{
	int		i;
	int		j;
	bool	found;
	int		est;

	found = false;
	est = *(stack[find_est_sign_based(stack, sign)]);
	j = 1;
	if (value *sign >= est * sign)
		return (find_est_sign_based(stack, -sign));
	while (!found)
	{
		i = 0;
		while (stack[i] && !found)
		{
			if (*(stack[i]) == value +(j * sign))
				found = true;
			else
				i++;
		}
		j++;
	}
	return (i);
}

int	next_value_in_stack(int	**stack, int value)
{
	return (adjacent_value_in_stack(stack, value, 1));
}

int	previous_value_in_stack(int **stack, int value)
{
	return (adjacent_value_in_stack(stack, value, -1));
}

int	find_of_value(int **stack, int value)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (*(stack[i]) == value)
			return (i);
		i++;
	}
	return (-1);
}
