/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:16:04 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/27 15:13:10 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			return (n * sign);
		n = n * 10 + *str - '0';
		++str;
	}
	return (n * sign);
}

int	*set_vars(char **argv, int *philos, int argc)
{
	// int	number_of_philosophers;
	// int	time_to_die;
	// int	time_to_eat;
	// int	time_to_sleep;
	// int	number_of_times_each_philosopher_must_eat;

	philos[0] = ft_atoi(argv[1]);
	philos[1] = ft_atoi(argv[2]);
	philos[2] = ft_atoi(argv[3]);
	philos[3] = ft_atoi(argv[4]);
	if (argc > 4)
		philos[4] = ft_atoi(argv[5]);
	return (philos);
}

int	create_threads(int philos)
{
	int	i;

	i = 0;
	while (i != philos)
	{
		//pthread_create();
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		*philos;
	int		i;

	philos = malloc(sizeof(int) * (argc - 1));
	if (!philos)
		return (0);
	philos = set_vars(argv, philos, argc);
	i = -1;
	while (philos[++i])
		printf("%i\n", philos[i]);
	//create_threads(philos[0]);
	return (0);
}