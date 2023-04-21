/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:06:11 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/21 21:43:23 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

char	**reformat_input(char **argv, int *argc);
void	*free_matrix(char **mat, int last_index);

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

static int	free_all(t_data *data, char ***args, int argc)
{
	if ((*args)[argc])
	{
		(*args)[0] = NULL;
		free_matrix(*args, argc);
		(*args) = NULL;
	}
	return (free_data(data));
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**args;

	args = reformat_input(argv, &argc);
	if (argc <= 3 || !args)
		return (1);
	data.error = ft_init(&data, args, argc);
	if (data.error != 0)
	{
		if (data.error == -1)
			write(2, "Error\n", 6);
		return (free_all(&data, &args, argc));
	}
	if (rename_values(data.array, data.tot_len, &(data.error)))
		return (free_all(&data, &args, argc));
	if (data.tot_len == 3)
		solve_3(data.stack_a, 'a');
	else if (data.tot_len <= 5)
		solve_5(&data);
	else
		quick_sort_algo(&data);
	return (free_all(&data, &args, argc));
}
