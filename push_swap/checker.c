/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/19 16:55:35 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 1o while anda entre argumentos, 2o while anda dentro dos argumentos

int	splitstr(char *argv, char c, t_list s_stack_a)
{
	int		n_args;
	char	**args;
	t_list	*curr;

	curr = &s_stack_a;
	args = ft_split(argv, c);
	n_args = 0;
	while (args[n_args])
		ft_addtolist(&curr, ft_atoi(args[n_args++]));
	return (1);
}

int check_argv(char **argv, t_list s_stack_a)
{
	int		i;
	int		j;
	int		n_split;
	t_list	*curr;

	curr = &s_stack_a;
	i = 0;
	while (argv[++i])
	{
		j = 0;
		n_split = 0;
		while (argv[i][j])
		{
			// Checks for space, tab, line feed, vertical tab, carriage return)
			if (argv[i][j] == 32 || argv[i][j] == 9 || argv[i][j] == 10
				|| argv[i][j] == 11 || argv[i][j] == 13)
			{
				// The argument is a string, use ft_split
				n_split = splitstr(argv[i], argv[i][j], s_stack_a);
				break ;
			}
			// Checks if the there are any non-numeric chars in the arguments
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				exit (ft_printf("%s\n", "Error 2"));
			j++;
		}
		// If there are no non-numeric chars
		if (n_split == 0)
			ft_addtolist(&curr, ft_atoi(argv[i]));
	}
	return (0);
}
