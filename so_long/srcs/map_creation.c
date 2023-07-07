/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:14 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 18:11:32 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_check(char *file)
{
	char	*ber;
	int		i;

	i = 0;
	ber = ".ber";
	while (file[i])
		i++;
	i = i - 4;
	while (file[i])
	{
		if (file[i] != *ber)
			exit(ft_printf("%s\n", "File isn't a .ber file"));
		i++;
		ber++;
	}
}

char	*map_string(int fd)
{
	char	*buf;
	int		i;
	int		n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		exit(ft_printf("%s\n", "Failed malloc in map_string"));
	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i != 0)
			n = i;
		if (i == -1)
		{
			free(buf);
			exit(ft_printf("%s\n", "Failed reading fd in map_string"));
		}
	}
	buf[n] = '\0';
	return (buf);
}

int	n_lines(int fd)
{
	int		n;
	int		i;
	char	*buf;

	buf = map_string(fd);
	i = 0;
	n = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			n++;
		i++;
	}
	free(buf);
	if (n < 2)
		exit(ft_printf("%s\n", "Invalid map"));
	return (n);
}

t_map	map_creation(char *file)
{
	t_map	struct_map;
	char	*line;
	char	**map;
	int		fd;

	file_check(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("%s\n", "Couldn't open file"));
	map = malloc(sizeof(char *) * (n_lines(fd) + 2));
	if (map == NULL)
		exit(ft_printf("%s\n", "Failed malloc in map_creation"));
	fd = open(file, O_RDONLY);
	struct_map.rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[struct_map.rows++] = line;
	}
	map[struct_map.rows] = 0;
	struct_map.map = map;
	return (struct_map);
}
