/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:31:35 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 14:04:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_init(int **len_arr, int **sub_s, int len)
{
	int	i;

	*len_arr = malloc(len * sizeof(int));
	if (!len_arr)
		return (NULL);
	*sub_s = malloc(len * sizeof(int));
	if (!*sub_s)
	{
		free(*len_arr);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		(*len_arr)[i] = 1;
		(*sub_s)[i] = i;
		i++;
	}
	return (*len_arr);
}

int	*arr_fill(int **stack, int ***lis, int start, int len)
{
	int	i;
	int	j;
	int	*len_arr;
	int	*sub_sequence;

	if (!arr_init(&len_arr, &sub_sequence, len))
		return (NULL);
	i = 0;
	while (i++ < len - 1)
	{
		j = 0;
		while (j < i)
		{
			if (*stack[next_n(stack, start, j)] \
			< *stack[next_n(stack, start, i)] && len_arr[i] < len_arr[j] + 1)
			{
				len_arr[i] = len_arr[j] + 1;
				sub_sequence[i] = j;
			}
			j++;
		}
	}
	(*lis)[0] = len_arr;
	(*lis)[1] = sub_sequence;
	return (sub_sequence);
}

// int	*arr_fill(int **stack, int ***lis, int start, int len)
// {
// 	int	i;
// 	int	j;
// 	int	*len_arr;
// 	int	*sub_sequence;

// 	if (!arr_init(&len_arr, &sub_sequence, len))
// 		return (NULL);
// 	i = 0;
// 	while (i++ < len - 1)
// 	{
// 		j = 0;
// 		while (j < i)
// 		{
// 			if (*stack[next_n(stack, start, j)] 
// 			< *stack[next_n(stack, start, i)] && len_arr[i] < len_arr[j] + 1)
// 			{
// 				len_arr[i] = len_arr[j] + 1;
// 				sub_sequence[i] = j;
// 			}
// 			j++;
// 		}
// 	}
// 	(*lis)[0] = len_arr;
// 	(*lis)[1] = sub_sequence;
// 	return (sub_sequence);
// }

int	*get_sub_sequence(int **lis, int sub_s_end, int **stack)
{
	int	*sub_sequence;
	int	len;
	int	i;
	int	j;

	sub_sequence = malloc(sizeof(int) * lis[0][sub_s_end]);
	if (!sub_sequence)
	{
		free(lis[1]);
		return (NULL);
	}
	len = lis[0][sub_s_end];
	j = sub_s_end;
	i = 0;
	while (i < len)
	{
		sub_sequence[len - 1 - i] = *stack[j];
		j = lis[1][j];
		i++;
	}
	free(lis[1]);
	lis[0][0] = len;
	return (sub_sequence);
}

int	**format_lis(int **lis, int **stack, int len)
{
	int	i;
	int	highest;

	i = 1;
	highest = 0;
	while (i < len)
	{
		if (lis[0][i] > lis[0][highest])
			highest = i;
		i++;
	}
	lis[1] = get_sub_sequence(lis, highest, stack);
	len = lis[0][0];
	free(lis[0]);
	if (!lis[1])
		return (NULL);
	lis[0] = malloc(sizeof(int));
	if (!lis[0])
	{
		free(lis[1]);
		return (NULL);
	}
	**lis = len;
	return (lis);
}

int	**get_lis(int **stack, int start, int len)
{
	int	**lis;

	lis = malloc(2 * sizeof(int *));
	if (!lis)
		return (NULL);
	if (!arr_fill(stack, &lis, start, len))
		return (NULL);
	lis = format_lis(lis, stack, len);
	return (lis);
}
