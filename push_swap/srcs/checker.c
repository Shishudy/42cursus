/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/02/03 17:48:38 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*splitstr(char *argv, char c, t_list *s_a)
{
	int		i;
	char	**args;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < 48 || argv[i] > 57) && argv[i] != c)
			exit (ft_printf("%s\n", "Non-numeric in splistr"));
		i++;
	}
	args = ft_split(argv, c);
	i = 0;
	while (args[i])
		ft_addtolist(&s_a, ft_atoi(args[i++]));
	return (s_a);
}
// 1o while anda entre argumentos, 2o while anda dentro dos argumentos
t_list *check_argv(char **argv, t_list *s_a)
{
	int		i;
	int		j;
	int		n_split;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		n_split = 0;
		while (argv[i][j])
		{
			// Checks for space, tab, line feed, vertical tab, carriage return)
			if (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
			{
				// The argument is a string, use ft_split
				s_a = splitstr(argv[i], argv[i][j], s_a);
				n_split = 1;
				break ;
			}
			// Checks if the there are any non-numeric chars in the arguments
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				exit (ft_printf("%s\n", "Non-numeric in check_argv"));
			j++;
		}
		// If there are no non-numeric chars
		if (n_split == 0)
			ft_addtolist(&s_a, ft_atoi(argv[i]));
	}
	return (s_a);
}
