/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:19:09 by fedmarti          #+#    #+#             */
/*   Updated: 2023/02/07 16:22:08 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>

enum	e_sequence_type
{
	Not_in_sequence,
	Sequence_stopper,
	To_be_switched_l,
	To_be_switched_r,
	To_be_switched_b,
	Injection_point,
	Left_eois,
	Right_eois,
	Left_eos,
	Right_eos,
	In_sequence
};

typedef struct nodes
{
	enum e_sequence_type	type;
	char					stack;
	int						index;
	int						value;
	int						index_of_previous_value;
	int						index_of_next_value;
	int						previous;
	int						next;
}	t_node;

typedef struct stacks
{
	int	**stack_a;
	int	**stack_b;
	int	*array;
	int	tot_len;
	int	error;
}	t_data;

void	sorting_algorithm(t_data *data);
int		stack_len(int **stack);
int		rename_values(int *array, int len, int *error);
int		rotate_stack(int **stack, int dir, int len);
int		swap_stack(int **stack);
int		push_stack(int **stack_1, int **stack_2);
void	swap_a(int **stack);
void	swap_b(int **stack);
void	swap_both(int **stack_a, int **stack_b);
void	push_a(int **stack_a, int **stack_b);
void	push_b(int **stack_b, int **stack_a);
void	rotate_a(int **stack, int dir);
void	rotate_b(int **stack, int dir);
void	rotate_both(int **stack_a, int **stack_b, int dir);
int		ft_init(t_data *data, char **argv, int argc);
int		get_direction(int **stack, int target, int goal);
int		get_distance(int **stack, int target, int goal);
int		next(int **stack, int index);
int		previous(int **stack, int index);
int		adjacent(int **stack, int index, int sign);
int		find_of_value(int **stack, int value);
int		previous_value_in_stack(int **stack, int value);
int		next_value_in_stack(int	**stack, int value);
int		adjacent_value_in_stack(int **stack, int value, int sign);
int		get_junk_length(int **stack, int target, int direction);
int		rotate_to_goal(int **stack, int target, int goal);
int		find_highest(int **stack);
int		find_lowest(int **stack);
int		find_est_sign_based(int **stack, int sign);
int		get_sequence_length(int **stack, int index, int direction);
int		adjacent_n(int **stack, int index, int amount, int direction);
int		next_n(int **stack, int index, int amount);
int		previous_n(int **stack, int index, int amount);
bool	base_2_radix_sort(t_data *data);
void	push_back(t_data *data);
bool	is_sorted(int **stack, int len);
int		sign(int a);
int		abs(int a);
void	quick_sort(t_data *data);
void	solve_3(int **stack, char name);
void	swap_name(int **stack, char name);
void	push_name(int **stack, int **ausiliary, char name);
void	rotate_name(int **stack, int dir, int len, char name);
int		max(int a, int b);
int		min(int a, int b);
void	barista_sort(t_data *data);
void	merge_sort(t_data *data);
int		find_est_sign_based_size(int **stack, int sign, int size);
int		find_highest_size(int **stack, int size);
int		find_lowest_size(int **stack, int size);
void	syncronized_rotation(t_data *data, int target_a, int target_b);
void	rotate_to_goal_flag(t_data *data, int target, int goal, int flag);

#endif
