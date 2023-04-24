/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_quick_sort.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:08:02 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 22:18:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSEUDO_QUICK_SORT_H
# define PSEUDO_QICK_SORT_H
# include "push_swap.h"

typedef struct s_seq_list
{
	struct s_seq_list	*parent;
	struct s_seq_list	*child;
	int					len;
	int					highest_val;
	int					lowest_val;
	int					**stack;
	char				stack_name;
}	t_list_node;

void		free_list(t_list_node *list);
t_list_node	*get_n_child(t_list_node *list, int n);
int			free_data_list(t_data *data, t_list_node *list);
t_list_node	*free_node(t_list_node *node);
t_list_node	*node_init(t_list_node *parent, int pivot);
t_list_node	*split_n_times(t_list_node *parent, int times);
t_list_node	*list_init(t_data *data);
bool		in_range(int min, int max, int num);
bool		in_2_ranges(int *range_1, int *range_2, int num);
void		get_metrics(int *metric, t_list_node *list);
void		stack_update(t_list_node *list, t_data *data, char name);
int			prep_4_div(t_data *data, t_list_node *node, int **lis, int *met);
bool		div_check_2(t_list_node *list, int **lis, int *metric, int start);
void		divide_in_three_lis(t_data *data, t_list_node *list, int **lis);
int			list_len(t_list_node *head);
t_list_node	*get_est_node(t_list_node *head, int sign);
t_list_node	*get_highest_node(t_list_node *head);
t_list_node	*get_lowest_node(t_list_node *head);
t_list_node	*set_first(t_list_node *head, t_list_node *node);
t_list_node	*reverse_list(t_list_node *head);
t_list_node	*sort_list(t_list_node *head, int len);
void		divide_in_two_lis(t_data *data, t_list_node *list, int **lis);
int			prepare_for_division_no_metric(t_data *data, int **lis);
void		last_group_lis(t_data *data, t_list_node *current, int **lis);
void		sync_rotate_to_goal_dist(t_data *data, int dist);
void		syncronized_rotation_alt(t_data *data, int ta, int tb, int dir);
void		prepare_for_insertion(t_data *data, int *qp);
void		insertion_sort(t_data *data);
int			get_n_chunks(int len);
void		quick_sort_algo(t_data *data);

#endif