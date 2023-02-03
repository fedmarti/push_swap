/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:18:53 by fedmarti          #+#    #+#             */
/*   Updated: 2023/01/16 15:18:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	arr_find_lowest(int *arr, int len)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < len)
	{
		if (arr[pos] > arr[i])
			pos = i;
		i++;
	}
	return (pos);
}

static int	next_lowest(int *arr, int len, int reference)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (arr[pos] <= reference && i < len)
	{
		pos++;
		i++;
	}
	i = 1;
	while (i < len)
	{
		if (arr[pos] > arr[i] && arr[i] > reference)
			pos = i;
		i++;
	}
	return (pos);
}

static void	rename_from_reference(int *array, int len, int *positions)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[positions[i]] = i + 1;
		i++;
	}
}

/* Function takes an int array and its length as arguments and "renames"*/
/* each int by their cardinal position:*/
/* the smallest number becomes 1, the second smallest becomes 2...*/
/* It does this by saving the indexes of the numbers in increasing order */
/* on a temporary array*/
/* and then cycling through that array and changing the values accordingly*/

int	rename_values(int *array, int len, int *error)
{
	int	i;
	int	*positions;

	positions = malloc(len * sizeof(int));
	if (!positions)
	{
		*error = 1;
		return (1);
	}
	positions[0] = arr_find_lowest(array, len);
	i = 1;
	while (i < len)
	{
		positions[i] = next_lowest(array, len, array[positions[i - 1]]);
		i++;
	}
	rename_from_reference(array, len, positions);
	free(positions);
	return (0);
}
