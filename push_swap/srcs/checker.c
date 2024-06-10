/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 18:07:03 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_atoi(char **argv, t_list *a)
{
	long int	value;
	int			sign;

	value = 0;
	sign = 1;
	while ((**argv == 32 || (**argv >= 9 && **argv <= 13)) && **argv)
		(*argv)++;
	if (**argv == '-')
	{
		sign = -1;
		(*argv)++;
	}
	if ((**argv < '0' || **argv > '9') && **argv != '\0')
		deallocate(&a, 1);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (value * 10 < value)
			deallocate(&a, 1);
		value = value * 10 + **argv - '0';
		(*argv)++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648 || \
		(**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate(&a, 1);
	return (value * sign);
}

t_list	*check_argv(char **argv, t_list *a)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_addtolist(&a, split_atoi(&argv[i], a));
		i += !(*argv[i]);
	}
	if (list_sorted(&a))
		deallocate(&a, 2);
	return (a);
}
