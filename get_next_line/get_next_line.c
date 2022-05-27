/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:35:45 by rasantos          #+#    #+#             */
/*   Updated: 2022/05/23 16:35:47 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *max_fd)
{
	char	*buf[BUFFER_SIZE + 1];
	char	*s;
	int		i;

	i = 0;
	while(*max_fd[i] != '\n' && *max_fd[i] != '\0')
		i++;
	if(*max_fd[i] == '\n' && *max_fd[i + 1] != '\0')
	{
		read(fd, *buf, BUFFER_SIZE);
		while(i-- != -1 && *buff != '\n')
		{
			*s++ = *buf++;
		}
		*s++ = '\n';
		*s = '\0';
	}
	else
	{
		while(i-- != -1 && *buf != '\0')
		{
			*s++ = *buf++;
		}
		*s = '\0';
		max_fd++;
	}
	i = 0;
	return(s);
}

char	*ft_getline(int fd, char *max_fd)
{
	char	*buf[BUFFER_SIZE + 1];
	int		red;
	int		i;

	red = read(fd, buf, BUFFER_SIZE);
	while(red-- > 0)
	{
		if (buf[i] == '\n')
		{
			ft_
		}
	}


}

char	*get_next_line(int fd)
{
	static	char	*max_fd[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	return (ft_getline(fd, max_fd));
}
