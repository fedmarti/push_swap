/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:13:13 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 22:14:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	swap_a(int **stack)
{
	swap_stack(stack);
	write (1, "sa\n", 3);
}

void	swap_b(int **stack)
{
	swap_stack(stack);
	write(1, "sb\n", 3);
}

void	swap_both(int **stack_a, int **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write (1, "ss\n", 3);
}

void	push_a(int **stack_a, int **stack_b)
{
	push_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(int **stack_b, int **stack_a)
{
	push_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}
