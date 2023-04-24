/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_list_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:18:22 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:21:47 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_quick_sort.h"

int	free_data_list(t_data *data, t_list_node *list)
{
	free_data(data);
	free_list(list);
	return (1);
}

bool	in_range(int min, int max, int num)
{
	return (num >= min && num <= max);
}

bool	in_2_ranges(int *range_1, int *range_2, int num)
{
	return (in_range(range_1[0], range_1[1], num)
		|| in_range(range_2[0], range_2[1], num));
}

void	stack_update(t_list_node *list, t_data *data, char name)
{
	list->stack_name = name;
	list->stack = stack_from_name(data, name);
}

int	list_len(t_list_node *head)
{
	t_list_node	*current;
	int			i;

	i = 0;
	current = head;
	while (current)
	{
		current = current->child;
		i++;
	}
	return (i);
}
