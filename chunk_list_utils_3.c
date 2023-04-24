/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_list_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:18:22 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:22:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_quick_sort.h"

t_list_node	*get_est_node(t_list_node *head, int sign)
{
	t_list_node	*highest;

	highest = head;
	while (head->child)
	{
		head = head->child;
		if (head->highest_val * sign > highest->highest_val * sign)
			highest = head;
	}
	return (highest);
}

t_list_node	*get_highest_node(t_list_node *head)
{
	return (get_est_node(head, 1));
}

t_list_node	*get_lowest_node(t_list_node *head)
{
	return (get_est_node(head, -1));
}

t_list_node	*set_first(t_list_node *head, t_list_node *node)
{
	if (node == head)
		return (head);
	node->parent->child = node->child;
	if (node->child)
		node->child->parent = node->parent;
	node->parent = NULL;
	head->parent = node;
	node->child = head;
	return (node);
}

t_list_node	*reverse_list(t_list_node *head)
{
	t_list_node	*current;
	t_list_node	*temp;

	head = set_first(head, get_n_child(head, -1));
	current = head;
	while (current->child)
	{
		temp = current;
		current = current->child;
		current = set_first(current, get_n_child(current, -1));
		current->parent = temp;
		temp->child = current;
	}
	return (head);
}
