/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:06:11 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/22 02:54:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    int *array;
    int **stack_a;
    int **stack_b;
    int check;

    if (argc < 2)
        return (1);
    array = &argc;
    check = ft_init(&array, &stack_a, &stack_b, argv);
    if (check != 0)
    {
        if (check == -1)
            write(1, "Error\n", 6);
        return (1);
    }
	sorting_algorithm(stack_a, stack_b);
    for (int i = 0; i < argc - 1; i++)
        printf("%i, ", (*stack_a)[i]);
	free(array);
	free(stack_a);
	free(stack_b);
}
