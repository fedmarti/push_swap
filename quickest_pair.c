/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickest_pair.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:26:03 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:15:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*calculate_couple(int **src_stack, int **dest_stack, int i)
{
	int	*result_1;
	int	*result_2;

	result_1 = moves_to_push(src_stack, dest_stack, i, 1);
	if (!result_1)
		return (NULL);
	result_2 = moves_to_push(src_stack, dest_stack, i, -1);
	if (!result_2)
	{
		free(result_1);
		return (NULL);
	}
	if (ft_abs(result_1[0]) <= ft_abs(result_2[0]))
	{
		free(result_2);
		return (result_1);
	}
	else
	{
		free(result_1);
		return (result_2);
	}
}

static int	*get_couple(t_data *data, char src_name, int i)
{
	int	*couple;
	int	**src_stack;
	int	**dest_stack;

	src_stack = stack_from_name(data, src_name);
	dest_stack = stack_from_name(data, opposite_name(src_name));
	couple = calculate_couple(src_stack, dest_stack, i);
	return (couple);
}

int	*quickest_pair(t_data *data, char src_name)
{
	int	*qp;
	int	*temp;
	int	i;
	int	len;

	len = stack_len(stack_from_name(data, src_name));
	i = 0;
	qp = get_couple(data, src_name, i);
	while (i++ < len - 1 && qp && qp[0])
	{
		temp = get_couple(data, src_name, i);
		if (!temp)
		{
			free(qp);
			return (NULL);
		}
		else if (ft_abs(temp[0]) < ft_abs(qp[0]))
		{
			free(qp);
			qp = temp;
		}
		else
			free(temp);
	}
	return (qp);
}
