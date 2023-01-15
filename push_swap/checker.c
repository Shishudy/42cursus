/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/15 19:23:29 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// 1o while anda entre argumentos, 2o while anda dentro dos argumentos
int check_argv(char **argv, t_list s_stack_a)
{
	int		i;
	int		j;
	int		split_char;

	i = 1;
	while (argv[i])
	{
		j = 0;
		split_char = 0;
		while (argv[i][j])
		{
			// Checks for space, tab, line feed, vertical tab, carriage return)
			if (argv[i][j] == (32 || 9 || 10 || 11 || 13))
			{
				// The argument is a string, use ft_split
				ft_split(argv[i++], argv[i][j]);
				split_char = 1;
				break ;
			}
			// Checks if the there are any non-numeric chars in the arguments
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				exit ("Error");
			j++;
		}
		// If there are no non-numeric chars
		if (split_char == 0)
			ft_lstadd_back(&s_stack_a, ft_lstlast(ft_atoi(argv[i++])));
	}
	return (0);
}
// Checks list for numbers bigger than int
int	check_list(t_list s_stack_a)
{
	t_list *stack;

	stack = &s_stack_a;
	while (stack != NULL)
	{
		if (stack->x > 2147483647 || stack->x < -2147483648)
			exit ("Error");
		stack = stack->next;
	}
	return (0);
}