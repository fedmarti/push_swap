/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_low_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:28:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/21 01:21:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_name(int **dest, int **src, char dest_name)
{
	push_stack(src, dest);
	write(1, "p", 1);
	write(1, &dest_name, 1);
	write(1, "\n", 1);
}

void	swap_name(int **stack, char name)
{
	swap_stack(stack);
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rotate_name(int **stack, int dir, int len, char name)
{
	rotate_stack(stack, dir, len);
	write(1, "r", 1);
	if (dir == -1)
		write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	solve_3(int **stack, char name)
{
	if (*stack[0] == 1 && *stack[1] == 3)
	{
		swap_name(stack, name);
		rotate_name(stack, 1, 3, name);
	}
	else if (*stack[0] == 2)
	{
		if (*stack[1] == 3)
			rotate_name(stack, -1, 3, name);
		else
			swap_name(stack, name);
	}
	else if (**stack != 1)
	{
		if (*stack[1] == 1)
			rotate_name(stack, 1, 3, name);
		else
		{
			swap_name(stack, name);
			rotate_name(stack, -1, 3, name);
		}
	}
}

/* evil branchless fuckery, temp is 1 if member 0 is greater than member 2*/
/* and is 0 otherwise. I sum that to the result of the operation i[0] < i[2]*/
/* so triplet[0] ends up being 1 + (1 * n of true results) */
void	init_triplet(int *triplet, int **stack)
{
	int	temp;

	temp = (*stack[0] > *stack[1]);
	triplet[0] = 1 + temp + (*stack[0] > *stack[2]);
	triplet[1] = 2 - temp + (*stack[1] > *stack[2]);
	triplet[2] = 6 - triplet[0] - triplet[1];
}
