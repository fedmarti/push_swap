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
