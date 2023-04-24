/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reformat_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:56:28 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 20:49:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_matrix(char **mat, int last_index);

static int	matrix_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

static void	copy_matrix(char **dest, char **src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

static char	*get_null_str(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	return (str);
}

static char	**null_termination(char **args, int *argc)
{
	args[*argc] = get_null_str();
	if (!args[*argc])
	{
		args[0] = NULL;
		free_matrix(args, *argc - 1);
		args = NULL;
	}
	return (args);
}

char	**reformat_input(char **argv, int *argc)
{
	char	**args;
	char	*arg_zero;
	char	**split;
	int		mat_len;

	if (*argc != 2)
		return (argv);
	arg_zero = argv[0];
	split = ft_split(argv[1], ' ');
	if (!split)
		return (NULL);
	mat_len = matrix_len(split);
	args = malloc(sizeof(char *) * (mat_len + 2));
	if (!args)
		return (NULL);
	args[0] = arg_zero;
	copy_matrix(&args[1], split, mat_len);
	free(split);
	*argc = mat_len + 1;
	args = null_termination(args, argc);
	return (args);
}
