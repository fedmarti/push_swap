/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:06:11 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/03 23:15:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

static int	free_all(t_data *data)
{
	if (data->array)
		free(data->array);
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	return (data->error);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	data.error = ft_init(&data, argv, argc);
	if (data.error != 0)
	{
		if (data.error == -1)
			write(1, "Error\n", 6);
		return (1);
	}
	if (rename_values(data.array, data.tot_len, &(data.error)))
		return (free_all(&data));
	//sorting_algorithm(&data);
	//quick_sort(&data);
	barista_sort(&data);
	return (free_all(&data));
}
