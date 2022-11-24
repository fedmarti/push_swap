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

void	sorting_algorithm(int **stack_a, int **stack_b);
int		stack_len(int **stack);
void	rotate_stack(int **stack, int dir, int len);
void	swap_stack(int **stack);
void	push_stack(int **stack_1, int **stack_2);
void	swap_a(int **stack);
void	swap_b(int **stack);
void	swap_both(int **stack_a, int **stack_b);
void	push_a(int **stack_a, int **stack_b);
void	push_b(int **stack_b, int **stack_a);
void	rotate_a(int **stack, int dir);
void	rotate_b(int **stack, int dir);
void	rotate_both(int **stack_a, int **stack_b, int dir);
int     ft_init(int **arr, int ***stack_a, int ***stack_b, char **argv);

#endif
