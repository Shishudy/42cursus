/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:40 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/15 17:33:33 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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


static void	signal_handler(int signum, siginfo_t *pid, void *palha)
{
	static int				i;
	static unsigned char	c;
	static pid_t			client_pid;
	static char				*client_str;

	(void)palha;
	client_pid = pid->si_pid;
	printf("client_pid: %d", client_pid);
	c = ((signum == SIGUSR1) << i) | c;
	i++;
	if (i == 8)
	{
		if (c)
			client_str = increment_new_data(c, client_str);
		else if (client_str)
		{
			ft_printf("%s\n", client_str);
			kill(client_pid, SIGUSR2); // "Recebido"
			client_str = NULL;
		}
		i = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1); // "contar quantidade de bytes"
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("%s", "SERVER PID: ");
	ft_printf("%d\n", pid);
	sig.sa_flags = SA_SIGINFO;          // Atribuir flags
	sig.sa_sigaction = &signal_handler; // disparar evento
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sigemptyset(&sig.sa_mask);
	/*sa_mask specifies a mask of signals which should be blocked
				(i.e.,
						added to the signal mask of the thread in which the signal
				handler is invoked) during execution of the signal handler.  In
				addition,
					the signal which triggered the handler will be blocked,
				unless the SA_NODEFER flag is used.*/
	while (1)
	{
		if (!SIGUSR1 && !SIGUSR2)
			pause();
	}
}

/**
 * @brief
 *
 * @param client_str Full string to return to client
 * @param new_char New byte info from new trigger
 * @return char* {new_string}
 */