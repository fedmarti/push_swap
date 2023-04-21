/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:08:49 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/21 00:58:59 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	stack_len(int **stack)
{
	int	len;

	len = 0;
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

int	push_stack(int **src, int **dest)
{
	int	len;

	if (!*src)
		return (1);
	len = stack_len(dest);
	if (len)
	{
		dest[len] = *src;
		rotate_stack(dest, -1, len + 1);
	}
	else
		*dest = *src;
	len = stack_len(src);
	rotate_stack(src, 1, len);
	src[len - 1] = NULL;
	return (0);
}

int	ft_abs(int a)
{
	return ((a * (a >= 0) - (a * (a < 0))));
}
