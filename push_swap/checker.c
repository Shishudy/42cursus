/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:12 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/11 17:07:00 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// 1o while anda entre argumentos, 2o while anda dentro dos argumentos
/**
 * @brief Creating 1° task

 */

/**
 * @brief 
 * {bolean} fez_split
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)

// Obrigado por continuar! Na boa! xD
{
	int	i;
	int	j;
	int	fez_split;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		j = 0;
		fez_split = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 32)
				return (1);
			if (argv[i][j] == 32)
			{
				ft_split(argv[i++], ' ');
				fez_split = 1;
				break ;
			}
			j++;
		}
		if (fez_split == 0)
			ft_atoi(argv[i++]);
	}
	return (0);
}
