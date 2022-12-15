/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:44:58 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/15 21:23:37 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_sendbit(int pid, char byte)
{
	int i;

	i = 0;
	while (i++ < 8)
	{
		if (byte & 1)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		byte = (byte >> 1);
	}
}

int main(int argc, char **argv)
{
	int pid;
	int i;
	char *client_msg;

	if (argc != 3)
		return (ft_printf("Error: Wrong number of arguments\n"));
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
		return (ft_printf("Error: Invalid PID\n"));
	client_msg = argv[2];
	i = 0;
	while (client_msg  && 1)
	{
		ft_sendbit(pid, client_msg[i]);
		if (!client_msg[i++])
			break ;
	}
	return (0);
}