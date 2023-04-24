/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:54 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:44:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd);
int		perform_action_2(char *action, t_data *data);
char	**reformat_input(char **argv, int *argc);
void	*free_matrix(char **mat, int last_index);
int		free_data(t_data *data);

static int	free_all(t_data *data, char ***args, int argc)
{
	if ((*args)[argc])
	{
		(*args)[0] = NULL;
		free_matrix(*args, argc + 1);
		(*args) = NULL;
	}
	return (free_data(data));
}

bool	ft_strcmp(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == cmp[i])
	{
		i++;
	}
	if (str[i] != cmp[i])
		return (false);
	return (true);
}

int	perform_action(char *action, t_data *data)
{
	if (ft_strcmp(action, "sa\n"))
		swap_stack(data->stack_a);
	else if (ft_strcmp(action, "sb\n"))
		swap_stack(data->stack_b);
	else if (ft_strcmp(action, "ss\n"))
	{
		swap_stack(data->stack_b);
		swap_stack(data->stack_a);
	}
	else if (ft_strcmp(action, "ra\n"))
		rotate_stack(data->stack_a, 1, stack_len(data->stack_a));
	else if (ft_strcmp(action, "rb\n"))
		rotate_stack(data->stack_a, 1, stack_len(data->stack_b));
	else if (ft_strcmp(action, "rr\n"))
	{
		rotate_stack(data->stack_a, 1, stack_len(data->stack_a));
		rotate_stack(data->stack_a, 1, stack_len(data->stack_b));
	}
	else if (ft_strcmp(action, "rra\n"))
		rotate_stack(data->stack_a, -1, stack_len(data->stack_a));
	else if (ft_strcmp(action, "rrb\n"))
		rotate_stack(data->stack_a, -1, stack_len(data->stack_b));
	else
		return (perform_action_2(action, data));
	return (1);
}

void	checker_behavior(t_data *data)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (!perform_action(action, data))
		{
			if (action)
				free(action);
			write(2, "Error\n", 6);
			return ;
		}
		free(action);
		action = get_next_line(0);
	}
	if (is_sorted(data->stack_a, data->tot_len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**args;

	if (argc < 2)
		return (0);
	args = reformat_input(argv, &argc);
	if (!args)
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
	checker_behavior(&data);
	return (free_all(&data, &args, argc));
}
