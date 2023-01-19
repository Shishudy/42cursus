/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:35:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/18 15:28:33 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder(int fd, char *remainder)
{
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(remainder, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(remainder);
			return (NULL);
		}
		buf[i] = '\0';
		remainder = ft_strjoin(remainder, buf);
	}
	free(buf);
	return (remainder);
}

char	*ft_new_line(char *remainder)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * i + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (remainder[i])
	{
		new_line[i] = remainder[i];
		if (remainder[i++] == '\n')
			break ;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*new_remainder;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!new_remainder)
		return (NULL);
	i = i + 1;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*remainder[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = ft_remainder(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	new_line = ft_new_line(remainder[fd]);
	remainder[fd] = ft_new_remainder(remainder[fd]);
	return (new_line);
}
