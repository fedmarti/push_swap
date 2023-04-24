/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_low_n_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:28:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 17:33:57 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_3_triplet(int **stack, char name, int *triplet)
{
	if (triplet[0] == 1 && triplet[1] == 3)
	{
		swap_name(stack, name);
		rotate_name(stack, 1, 3, name);
	}
	else if (triplet[0] == 2)
	{
		if (triplet[1] == 3)
			rotate_name(stack, -1, 3, name);
		else
			swap_name(stack, name);
	}
	else
	{
		if (triplet[1] == 1)
			rotate_name(stack, 1, 3, name);
		else
		{
			swap_name(stack, name);
			rotate_name(stack, -1, 3, name);
		}
	}
}

void	solve_3_any(int **stack, char name)
{
	int	triplet[3];
	int	len;

	len = stack_len(stack);
	init_triplet(triplet, stack);
	if (len == 3)
		return (solve_3_triplet(stack, name, triplet));
	if (triplet[0] == 3)
		swap_name(stack, name);
	if (triplet[2] != 3)
	{
		rotate_name(stack, 1, len, name);
		swap_name(stack, name);
		rotate_name(stack, -1, len, name);
	}
	if (*stack[0] > *stack[1])
		swap_name(stack, name);
}

/*321- -> swap, rotate, swap, reverse_rotate, swap.
 -312- -> swap, rotate, swap, reverse_rotate. -231- ->
 	 rotate, swap, reverse_rotate, swap.
 -132- -> rotate, swap, reverse_rotate.
 -213- -> swap
 -123-  -> ...*/