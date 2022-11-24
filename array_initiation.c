/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:16:02 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 22:18:36 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

static int    fill_both_stacks(int **arr, int ***stack_a, int ***stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		(*stack_a)[i] = &((*arr)[i]);
		(*stack_b)[i] = NULL;
		i++;
	}
	(*stack_a)[i] = NULL;
	(*stack_a)[i] = NULL;
	return (0);
}

static int	ft_atol(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		num *= 10;
		num += sign * (*str - '0');
		str++;
	}
	return (num);
}

static int is_number(char *str)
{
	int	phase;

	phase = 0;

    while (*str)
    {
		if (!phase && (*str != '-' && *str != '+' && *str != ' '))
			phase++;
        if (phase && (*str < '0' && *str > '9'))
            return (0);
		if (!phase && (*str == '-' || *str == '+'))
			phase++;
        str++;
    }
    return (1);
}

/* transfers the content of argv into the array, converting it from char to int */
/* returns 1 if the input is invalid */

static int fill_arr(int **arr, char **argv, int argc)
{
	int i;
	int r;
	long	num;

	i = 0;
	while (i < argc - 1)
	{
		if (!is_number(argv[i + 1]))
			return (1);
		num = ft_atol(argv[i + 1]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		(*arr)[i] = num;
		r = 0;
		while (r < i)
		{
			if ((*arr)[r] == (*arr)[i])
				return (1);
			r++;
		}
		i++;
	}
	return (0);
}

/* mallocs all the arrays and arrays of arrays */
/* returns 0 if no errors occurred, 1 if malloc failed, -1 if the input was was invalid */

int ft_init(int **arr, int ***stack_a, int ***stack_b, char **argv)
{
	int argc;

	argc = **arr;
	*arr = (int *) malloc((argc - 1) * sizeof(int));
	if (!*arr)
		return (1);
	*stack_a = (int **) malloc ((argc) * sizeof(int*));
	if (!*stack_a)
	{
        free(*arr);
        return (1);
	}
	*stack_b = (int **) malloc ((argc) * sizeof(int*));
	if (!stack_b)
	{
		free(*arr);
		free(*stack_a);
		return (1);
	}
	if (fill_arr(arr, argv, argc))
	{
		free(*arr);
		free(*stack_a);
		free(*stack_b);
		return (-1);
	}
	return (fill_both_stacks(arr, stack_a, stack_b, argc));
}
