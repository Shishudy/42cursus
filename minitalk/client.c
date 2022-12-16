/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:24:34 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/16 17:28:36 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bit_counter(int signum)
{
	static int	bit;
	static int	byte;

	if (signum == SIGUSR1)
	{
		bit++;
		if (bit == 8)
		{
			byte++;
			bit = 0;
		}
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("\nBytes received with success: %d\n", byte + 1);
		exit(0);
	}
}

void	ft_sendbit(int pid, char byte)
{
	int	c;

	c = 0;
	while (c < 8)
	{
		if (byte & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte = (byte >> 1);
		c++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*client_msg;

	if (argc != 3)
		return (ft_printf("Error: Wrong number of arguments\n"));
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
		return (ft_printf("Error: Invalid PID\n"));
	client_msg = argv[2];
	i = 0;
	signal(SIGUSR1, &ft_bit_counter);
	signal(SIGUSR2, &ft_bit_counter);
	while (client_msg && 1)
	{
		ft_sendbit(pid, client_msg[i]);
		if (!client_msg[i++])
			break ;
	}
	while (1)
		pause();
	return (0);
}
