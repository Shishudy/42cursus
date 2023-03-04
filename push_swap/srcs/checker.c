/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/03 14:01:30 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*splitstr(char *argv, char c, t_list *a)
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
		ft_addtolist(&a, ft_atoi(args[i++]));
	return (a);
}

t_list *check_argv(char **argv, t_list *a)
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
			if (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
			{
				a = splitstr(argv[i], argv[i][j], a);
				n_split = 1;
				break ;
			}
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				exit (ft_printf("%s\n", "Non-numeric in check_argv"));
			j++;
		}
		if (n_split == 0)
			ft_addtolist(&a, ft_atoi(argv[i]));
	}
	return (a);
}
