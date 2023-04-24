/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:54 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 16:48:51 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_strcmp(char *str, char *cmp);

int	free_data(t_data *data)
{
	if (data->array)
	{
		free(data->array);
		data->array = NULL;
	}
	if (data->stack_a)
	{
		free(data->stack_a);
		data->stack_a = NULL;
	}
	if (data->stack_b)
	{
		free(data->stack_b);
		data->stack_b = NULL;
	}
	return (data->error);
}

int	perform_action_2(char *action, t_data *data)
{
	if (ft_strcmp(action, "rrr\n"))
	{
		rotate_stack(data->stack_a, -1, stack_len(data->stack_a));
		rotate_stack(data->stack_a, -1, stack_len(data->stack_b));
	}
	else if (ft_strcmp(action, "pa\n"))
		push_stack(data->stack_b, data->stack_a);
	else if (ft_strcmp(action, "pb\n"))
		push_stack(data->stack_a, data->stack_b);
	else
		return (0);
	return (1);
}
