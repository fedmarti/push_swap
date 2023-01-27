/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:06 by fedmarti          #+#    #+#             */
/*   Updated: 2023/01/26 17:40:51 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	adjacent_n(int **stack, int index, int amount, int direction)
{
	while (amount--)
		index = adjacent(stack, index, direction);
	return (index);
}

int	next_n(int **stack, int index, int amount)
{
	return (adjacent_n(stack, index, amount, 1));
}

int	previous_n(int **stack, int index, int amount)
{
	return (adjacent_n(stack, index, amount, -1));
}

int get_junk_extreme(int **stack, int index, int direction)
{
	int	adjacent_i;

	adjacent_i = adjacent(stack, index, direction);
	while (adjacent_i != adjacent_value_in_stack(stack, index, direction))
	{
		index = adjacent_i;
		adjacent_i = adjacent(stack, index, direction);
	}
	return (index);
}
