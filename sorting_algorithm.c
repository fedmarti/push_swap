/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:59:06 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 21:59:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include "push_swap.h"

bool is_sorted(int **stack, int len)
{
	bool sorted;
	int i;

	i = 0;
	sorted = true;
	if (stack_len(stack) < len)
		return (false);
	while (i < len && sorted)
	{
		if (find_lowest(&(stack[i])) != 0)
			sorted = false;
		i++;
	}
	return (sorted);
}

bool is_greater_than_previous(int **stack_a, int pos, int len)
{
	int a;
	int b;

	a = *(stack_a[pos]);
	if (pos > 0)
		b = *(stack_a[pos - 1]);
	else
		b = *(stack_a[len - 1]);
	if (a > 1)
	{
		if (a > b)
			return (true);
		return (false);
	}
	if (b >= len)
		return (true);
	return (false);
}

/* Looks for the first node that isn't preceded by a smaller node,*/
/* starting from the edges (first, then last, second, second last, third...)*/
/* 	This doesn't apply if the node is of the lowest value*/
/* it will instead check if it's preceded by the highest value one.*/
/* 	The first node is compared with the last (pac-man effect)*/
int first_oor(stack *data, int len)
{
	int i;
	int temp;

	i = 0;
	temp = len / 2;
	while (i < temp)
	{
		if (!is_greater_than_previous(data->stack_a, i, len))
			return (i);
		if (!is_greater_than_previous(data->stack_a, len - i - 1, len))
			return (len - i - 1);
		i++;
	}
	return (-1);
}






/* checks if the previous number and the next one are respectively */
/* the previous and next number in the sequence */
/* example: */
/* stack = 1 3 4 2 5 */
/* *stack[index] = 5 */
/* next is 1 which is correct*/
/* previous is 2 when it's supposed to be 4 */
/* function returns false */

enum sequence_type	end_typecheck(int **stack, int index, int side)
{
	index = adjacent_value_in_stack(stack, *(stack[index]), side);
	if (adjacent_value_in_stack(stack, *(stack[index]), side) 
		== adjacent(stack, index, side))
		{
			if (side < 0)
				return (Left_eois);
			return (Right_eois);
		}
	if (side < 0)
		return (Left_eos);
	return (Right_eos);
} 

enum sequence_type	in_sequence_subcheck(int **stack, node current)
{
	if (current.next == current.index_of_next_value)
		{
			if (current.previous == current.index_of_previous_value)
				return (In_sequence);
			return (end_typecheck(stack, current.index, -1));
		}
	return (end_typecheck(stack, current.index, 1));
}

enum sequence_type	switch_subcheck(int **stack, node current)
{
	if (current.next != current.index_of_previous_value)
		return (To_be_switched_l);
	else if (current.previous != current.index_of_next_value)
		return (To_be_switched_r);
	return (To_be_switched_b);
}

//enum sequence_type{Not_in_sequence, Sequence_stopper, To_be_switched_l,
// To_be_switched_r, To_be_switched_b, 
// Left_eois, Right_eois, Left_eos, Right_eos, In_sequence};

node	sequence_check(int **stack, int index)
{	
	node	current;

	current.index = index;
	current.next = next(stack, index);
	current.previous = previous(stack, index);
	current.index_of_next_value = next_value_in_stack(stack, *(stack[index]));
	current.index_of_previous_value = previous_value_in_stack(stack, *(stack[index]));
	if (current.next == current.index_of_next_value
		|| current.previous == current.index_of_previous_value)
		current.type = in_sequence_subcheck(stack, current);
	else if (current.next == current.index_of_previous_value
		|| current.previous == current.index_of_next_value)
		current.type = switch_subcheck(stack, current);
	else if (next(stack, current.next) == next_value_in_stack(stack, current.next)
		|| previous(stack, current.previous) 
		== previous_value_in_stack(stack, current.previous))
		current.type = Sequence_stopper;
	else
		current.type = Not_in_sequence;
	return (current);
}

// first out of sequence
// order in which it searches 1->2->last->3->secondlast...

node first_oos(stack *data)
{
	int		i;
	int		j;
	int		len;
	node	current;

	i = 1;
	j = 0;
	len = stack_len(data->stack_a);
	current = sequence_check(data->stack_a, 0);
	while (i + j < len && current.type > 3)
	{
		if (i > j)
		{
			current = sequence_check(data->stack_a, len - j - 1);
			j++;
		}
		else
		{
			current = sequence_check(data->stack_a, i);
			i++;
		}
	}
	return (current);
}

void	full_sequence_logic(stack *data, int target)
{
	if ((data->stack_b)[0])
		target = find_of_value(data->stack_a, *((data->stack_b)[0]) + 1);
	else
		target = find_lowest(data->stack_a);
	if (target)
		rotate_to_goal(data, target, 0);
	else
		push_a(data->stack_a, data->stack_b);
}

void	swap_moves(stack *data, node current)
{
	int	goal;

	if (current.type == To_be_switched_l)
		goal == 0;
	else if (current.type == To_be_switched_r)
		goal == 1;
	else
	{
		if (get_distance(data->stack_a, current.index, 0) 
		< get_distance(data->stack_a, current.index, 1))
			current.type == To_be_switched_l;
		else 
			current.type == To_be_switched_r;
		return (swap_moves(data, current));
	}
	if (current.index == goal)
		swap_a(data->stack_a);
	else
		rotate_to_goal(data->stack_a, current.index, goal);
}

/*
enum sequence_type{Not_in_sequence, Sequence_stopper, To_be_switched_l,
	To_be_switched_r, To_be_switched_b, Left_eois, Right_eois, Left_eos,
	Right_eos, In_sequence};
*/


node	find_value(stack *data, int value)
{
	node	node;
	int		i;

	i = 0;
	node.value = value;
	node.index = -1;
	while((data->stack_a)[i] && node.index == -1)
	{
		if (*((data->stack_a)[i]) == value)
		{
			node.index = i;
			node.stack = 'a';
		}
		i++;
	}
	i = 0;
	while((data->stack_b)[i] && node.index == -1)
	{
		if (*((data->stack_b)[i]) == value)
		{
			node.index = i;
			node.stack = 'b';
		}
		i++;
	}
	return (node);
}

void	extraction_process(stack *data, int target, int goal, int amount)
{
	if (target != 0)
		rotate_to_goal(data->stack_a, target, 0);
	else
	{
		while (amount--)
			push_b(data->stack_b, data->stack_a);
	}
}

void	end_of_interrupted_sequence_moves(stack *data, node current)
{
	int	direction;
	int	goal;
	int	junk_len;
	int	seq_len;

	direction = 1;
	if (current.type == Left_eois)
		direction = -1;
	junk_len = get_junk_length(data->stack_a, current.index, direction);
	seq_len = get_sequence_length(data->stack_a, current.index, -direction);
	if (direction < 0)
	{
		if ((junk_len * 2) + get_distance(data->stack_a,
		adjacent_n(data->stack_a, current.index, junk_len, direction), 0) 
		> (seq_len * 2) + get_distance(data->stack_a, current.index, 0) 
		+ get_distance(data->stack_a, current.index,
		previous_value_in_stack(data->stack_a, current.value)))
		{
			extraction_process(data, current.index, previous_value_in_stack(data->stack_a, current.value), seq_len);
		}
		if ()
		
	}
}

void	decide_move(stack *data, node current)
{
	if (current.type >= To_be_switched_l && current.type <= To_be_switched_b)
		swap_moves(data, current);
	else if (current.type == Left_eois || current.type == Right_eois)
		end_of_interrupted_sequence_moves(data, current);
	else if (current.type == Left_eos)
		;
	else if (current.type == Right_eos)
		;
	else if (current.type == Sequence_stopper)
		;
	else if (current.type == Not_in_sequence)
		;
}

void sorting_algorithm(stack *data)
{
	int		i;
	int		len;
	node	target;

	i = 0;
	len = data->tot_len;
	while (!is_sorted(data->stack_a, data->tot_len))
	{
		target = first_oos(data);
		if (target.type == In_sequence)
			full_sequence_logic(data, target.index);
		else
			decide_move(data, target);
	}
}
 