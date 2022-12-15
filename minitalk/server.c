/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:40 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/15 21:41:06 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	write_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}*/

static char	*increment_new_data(char new_char, char *client_str)
{
	char	*server_str;
	size_t	len;

	len = 0;
	if (client_str)
		len = ft_strlen(client_str);
	server_str = (char *)malloc(sizeof(char) * (len + 2));
	if (server_str)
	{
		server_str = ft_memcpy(server_str, client_str, len);
		server_str[len] = new_char;
		server_str[len + 1] = '\0';
	}
	free(client_str);
	return(server_str);
}

static void	signal_handler(int signum, siginfo_t *pid, void *arg)
{
	static int				i;
	static unsigned char	c;
	//static char				*server_str;
	//static pid_t			client_pid;
	static char				*client_str;

	(void)arg;
	(void)pid;
	//client_pid = pid->si_pid;
	/*if (!server_str)
	{
		server_str = malloc(sizeof(char) * 1);
		server_str[0] = 0;
	}
	if (signum == SIGUSR1)
		c = c | 128;
	i++;
	if (i == 8)
	{
		server_str = increment_new_data(c, server_str);
		i = 0;
		if (!c)
			write_str(server_str);
	}
	else
		c = c >> 1;*/
	c = ((signum == SIGUSR1) << i) | c;
	i++;
	if (i == 8)
	{
		if (c)
			client_str = increment_new_data(c, client_str);
		else if (client_str)
		{
			ft_printf("%s\n", client_str);
			//kill(client_pid, SIGUSR2); // "Recebido"
			client_str = NULL;
		}
		i = 0;
		c = 0;
	}

	//kill(client_pid, SIGUSR1); // "contar quantidade de bytes"
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("%s", "SERVER PID: ");
	ft_printf("%d\n", pid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sigemptyset(&sig.sa_mask);
	while (1)
	{
		if (!SIGUSR1 && !SIGUSR2)
			pause();
	}
}
