/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:08:49 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 22:12:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	stack_len(int **stack)
{
	int	len;

	len = 0;
	while(stack[len] != NULL)
		len++;
	return (len);
}

void	rotate_stack(int **stack, int dir, int len)
{
	int *temp;
	int i;

	if (len < 2)
		return ;
	if (dir > 0)
	{
		temp = *stack;
		i = 0;
	}
	else
	{
		temp = stack[len - 1];
		i = len - 1;
	}
	while (len-- > 1)
	{
		stack[i] = stack[i + dir];
		i += dir;
	}
	stack[i] = temp;
}

void	swap_stack(int **stack)
{
	int *temp;
	
	if (!stack[0] || !stack[1])
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

/*takes the first element from stack1 and puts it at the front of stack2 */
/*also sets such spot as null and rotates 1, then shifts b          */

void	push_stack(int **stack_1, int **stack_2)
{
	int	len;

	if (!*stack_1)
		return ;
	len = stack_len(stack_2);
	stack_2[len - 1] = *stack_1;
	rotate_stack(stack_2, -1, len + 1);
	len = stack_len(stack_1);
	rotate_stack(stack_1, 1, len);
	stack_1[len - 1] = NULL;
}
