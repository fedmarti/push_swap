/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:19:09 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/24 21:56:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

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

char	**ft_split(char *src, char separator);
int		stack_len(int **stack);
int		rename_values(int *array, int len, int *error);
int		rotate_stack(int **stack, int dir, int len);
int		swap_stack(int **stack);
int		push_stack(int **src, int **dest);
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
int		rotate_to_goal(int **stack, int target, int goal, char name);
int		find_highest(int **stack);
int		find_lowest(int **stack);
int		find_est_sign_based(int **stack, int sign);
int		adjacent_n(int **stack, int index, int amount, int direction);
int		next_n(int **stack, int index, int amount);
int		previous_n(int **stack, int index, int amount);
bool	is_sorted(int **stack, int len);
int		sign(int a);
int		ft_abs(int a);
void	quick_sort_algo(t_data *data);
void	solve_3(int **stack, char name);
void	swap_name(int **stack, char name);
void	push_name(int **dest, int **src, char dest_name);
void	rotate_name(int **stack, int dir, int len, char name);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		find_est_sign_based_size(int **stack, int sign, int size);
int		find_highest_size(int **stack, int size);
int		find_lowest_size(int **stack, int size);
void	syncronized_rotation(t_data *data, int target_a, int target_b);
void	rotate_to_goal_flag(t_data *data, int target, int goal, int flag);
void	solve_3_any(int **stack, char name);
void	init_triplet(int *triplet, int **stack);
void	solve_2_any(int	**stack, char name);
int		free_data(t_data *data);
void	quick_sort_algo(t_data *data);
void	base_5_radix(t_data *data);
void	simple_radix(t_data *data);
void	rotate_other(t_data *data, char name, int dir);
void	push_other(t_data *data, char name);
int		**stack_from_name(t_data *data, char name);
char	name_from_sign(int sign);
int		sign_from_name(char name);
char	opposite_name(char name);
int		abs_max(int a, int b);
int		abs_min(int a, int b);
int		get_distance_sign(int **stack, int target, int goal, int sign);
int		*quickest_pair(t_data *data, char src_name);
int		*moves_to_push(int **src_stack, int **dest_stack, int target, int sign);
bool	in(int n, int *arr, int len);
void	free_couples(int **couples, int len);
void	syncronized_rotation_alt(t_data *data, int ta, int tb, int s);
int		**get_lis(int **stack, int start, int len);
int		abs_min_signed(int a, int b);
int		abs_max_signed(int a, int b);
void	insertion_sort(t_data *data);
void	solve_5(t_data *data);
void	free_lis(int **lis);

#endif
