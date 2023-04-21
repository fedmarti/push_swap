/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:45:37 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:13:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

// input a returns b and vice versa
char	opposite_name(char name)
{
	return ('b' * ('b' - name) + 'a' * (name - 'a'));
}

// 1 if a, -1 if b
int	sign_from_name(char name)
{
	return (('b' - name) - (name - 'a'));
}

char	name_from_sign(int sign)
{
	return ('a' * (sign > 0) + 'b' * (sign < 0));
}

int	**stack_from_name(t_data *data, char name)
{
	if (name == 'a')
		return (data->stack_a);
	if (name == 'b')
		return (data->stack_b);
	return (NULL);
}

int	abs_max(int a, int b)
{
	a = ft_abs(a);
	b = ft_abs(b);
	return (ft_max(a, b));
}
