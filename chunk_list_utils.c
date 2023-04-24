/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:18:22 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:32:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pseudo_quick_sort.h"

void	free_list(t_list_node *list)
{
	t_list_node	*next;

	if (!list)
		return ;
	while (list)
	{
		next = list->child;
		free(list);
		list = next;
	}
}

t_list_node	*get_n_child(t_list_node *list, int n)
{
	t_list_node	*next;

	if (n < 0)
		n = __INT_MAX__;
	if (list && n)
		next = list->child;
	else
		next = NULL;
	while (n-- && next)
	{
		list = next;
		next = list->child;
	}
	return (list);
}

t_list_node	*free_node(t_list_node *node)
{
	t_list_node	*temp;

	temp = NULL;
	if (node)
	{
		if (node->parent && node->child)
		{
			temp = node->child;
			node->parent->child = node->child;
			node->child->parent = node->parent;
		}
		else if (node->child)
		{
			node->child->parent = NULL;
			temp = node->child;
		}
		else if (node->parent)
			node->parent->child = NULL;
		free(node);
	}
	return (temp);
}

t_list_node	*node_init(t_list_node *parent, int pivot)
{
	t_list_node	*child;

	child = malloc(sizeof(struct s_seq_list));
	if (!child)
		return (NULL);
	child->parent = parent;
	child->child = NULL;
	child->highest_val = parent->highest_val;
	child->lowest_val = pivot;
	parent->highest_val = pivot - 1;
	child->len = child->highest_val - child->lowest_val + 1;
	parent->len = parent->len - child->len;
	child->stack = parent->stack;
	child->stack_name = parent->stack_name;
	return (child);
}

t_list_node	*list_init(t_data *data)
{
	t_list_node	*head;

	head = malloc(sizeof(struct s_seq_list));
	if (!head)
		return (NULL);
	head->parent = NULL;
	head->child = NULL;
	head->len = data->tot_len;
	head->highest_val = data->tot_len;
	head->lowest_val = 1;
	head->stack_name = 'a';
	head->stack = data->stack_a;
	return (head);
}
