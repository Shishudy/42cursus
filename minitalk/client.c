/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:44:58 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/15 17:35:02 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, char byte)
{
	int	i;
	int	b;

	i = 0;
	while (i < 8)
	{
		b = (byte >> i++) & b;
		if (b)
		{
			ft_printf("%d", b);
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_printf("%d", b);
			kill(pid, SIGUSR2);
		}
	}
}

void	ft_sendbyte(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_sendbit(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	char *client_msg;

	if (argc != 3)
		return (ft_printf("Error: Wrong number of arguments\n"));
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) < 0)
		return (ft_printf("Error: Invalid PID\n"));
	client_msg = argv[2];
	ft_sendbyte(pid, client_msg);
	return (0);
}