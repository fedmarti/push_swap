/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:31:38 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/20 20:12:52 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_min(int a, int b)
{
	a = ft_abs(a);
	b = ft_abs(b);
	return (ft_min(a, b));
}

int	abs_max_signed(int a, int b)
{
	int	res;

	res = (abs_max(a, b) == ft_abs(a));
	return (a * res + b * !res);
}

int	abs_min_signed(int a, int b)
{
	int	res;

	res = (abs_min(a, b) == ft_abs(a));
	return (a * res + b * !res);
}
