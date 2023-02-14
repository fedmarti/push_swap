/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:08:49 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/14 17:13:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	stack_len(int **stack)
{
	int	len;

	len = 0;
/*	if (_stack == NULL)
		return (len);*/
	while (stack[len] != NULL)
		len++;
	return (len);
}

int	rotate_stack(int **stack, int dir, int len)
{
	int	*temp;
	int	i;

	if (len < 2)
		return (1);
	if (dir > 0)
	{
		temp = *stack;
		i = 0;
	}
	else if (dir < 0)
	{
		temp = stack[len - 1];
		i = len - 1;
	}
	else
		return (1);
	while (len-- > 1)
	{
		stack[i] = stack[i + dir];
		i += dir;
	}
	stack[i] = temp;
	return (0);
}

int	swap_stack(int **stack)
{
	int	*temp;

	if (!stack[0] || !stack[1])
		return (1);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	return (0);
}

/*takes the first element from stack1 and puts it at the front of stack2 */
/*also sets such spot as null and rotates 1, then shifts b          */

int	push_stack(int **stack_1, int **stack_2)
{
	int	len;

	if (!*stack_1)
		return (1);
	len = stack_len(stack_2);
	if (len)
	{
		stack_2[len] = *stack_1;
		rotate_stack(stack_2, -1, len + 1);
	}
	else
		*stack_2 = *stack_1;
	len = stack_len(stack_1);
	rotate_stack(stack_1, 1, len);
	stack_1[len - 1] = NULL;
	return (0);
}

int	abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}
