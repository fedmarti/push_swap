/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:14:32 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 22:15:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	rotate_a(int **stack, int dir)
{
	rotate_stack(stack, dir, stack_len(stack));
	if (dir < 0)
		write(1, "r", 1);
	write(1, "ra\n", 3);
}

void	rotate_b(int **stack, int dir)
{
	rotate_stack(stack, dir, stack_len(stack));
	if (dir < 0)
		write(1, "r", 1);
	write(1, "rb\n", 3);
}

void	rotate_both(int **stack_a, int **stack_b, int dir)
{
	rotate_stack(stack_a, dir, stack_len(stack_a));
	rotate_stack(stack_b, dir, stack_len(stack_b));
	if (dir < 0)
		write(1, "r", 1);
	write(1, "rr\n", 3);
}
