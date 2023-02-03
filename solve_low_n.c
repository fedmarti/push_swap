/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_low_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:28:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/03 22:39:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_name(int **stack, int **ausiliary, char name)
{
	push_stack(stack, ausiliary);
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	swap_name(int **stack, char name)
{
	swap_stack(stack);
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

static void	rotate_name(int **stack, int dir, int len, char name)
{
	rotate_stack(stack, dir, len);
	write(1, "r", 1);
	if (dir == -1)
		write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	solve_3(int **stack, int **ausiliary, char name)
{
	if (stack[0] == 1 && *stack[1] == 3)
	{
		swap_name(stack, name);
		rotate_name(stack, 1, 3, name);
	}
	else if (stack[0] == 2)
	{
		if (*stack[1] == 3)
			rotate_name(stack, -1, 3, name);
		else
			swap_name(stack, name);
	}
	else
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
