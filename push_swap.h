/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:19:09 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 22:26:38 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
 
enum sequence_type{Not_in_sequence, Sequence_stopper, To_be_switched_l,
	To_be_switched_r, To_be_switched_b, Left_eois, Right_eois, Left_eos,
	Right_eos, In_sequence};

typedef struct nodes 
{
	enum sequence_type	type;
	char				stack;
	int					index;
	int					value;
	int					index_of_previous_value;
	int					index_of_next_value;
	int					previous;
	int					next;
}	node;

typedef struct stacks
{
	int	**stack_a;
	int	**stack_b;
	int	*array;
	int	tot_len;
	int	error;
}	stack;

void	sorting_algorithm(stack *data);
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
int		ft_init(stack *data, char **argv, int argc);
int		get_direction(int **stack, int target, int goal);
int		get_distance(int **stack, int target, int goal);
int		abs(int a);
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

#endif
