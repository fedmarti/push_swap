/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_list_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:18:22 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:24:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_quick_sort.h"

t_list_node	*split_n_times(t_list_node *parent, int times)
{
	t_list_node	*current;
	int			len;
	int			original_len;

	if (!parent)
		return (NULL);
	original_len = parent->len;
	len = original_len / times;
	current = parent;
	while (current && times > 1)
	{
		current->child = node_init(current, current->lowest_val + len);
		current = current->child;
		times--;
	}
	if (!current)
		return (NULL);
	return (current);
}

t_list_node	*sort_list(t_list_node *head, int len)
{
	int			i;
	t_list_node	*temp;
	t_list_node	*current;

	i = 1;
	head = set_first(head, get_lowest_node(head));
	current = head;
	while (current->child)
	{
		temp = current;
		current = current->child;
		if ((i & 1 && len & 1) || (!(i & 1) && !(len & 1)))
			current = set_first(current, get_highest_node(current));
		else
			current = set_first(current, get_lowest_node(current));
		current->parent = temp;
		temp->child = current;
		i++;
	}
	head = reverse_list(head);
	return (head);
}
