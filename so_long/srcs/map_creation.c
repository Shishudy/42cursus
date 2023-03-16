/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:14 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/15 21:09:04 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    file_format(char *file)
{
    char    *ber;
    int     i;

    i = 0;
    ber = ".ber";
    while (file[i])
    {
        if (file[i] == '.')
            break ;
        i++;;
    }
    while (file[i])
    {
        if (file[i] == *ber)
        {
            i++;;
            ber++;
        }
        else
            exit(ft_printf("%s\n", "File isn't a .ber file"));
    }
}

char    *map_string(int fd)
{
    char    *buf;
    int     i;
    int     n_lines;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
    i = 1;
    while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
	}
    return (buf);
}

int n_lines(int fd)
{
    int     n;
    char    *buf;

    buf = map_string(fd);
    if (!buf)
        exit(ft_printf("%s\n", "Error while creating map string"));
    n = 0;
    while (*buf)
    {
        if (*buf == '\n')
            n++;
        buf++;
    }
    free(buf);
    return (n);
}

/* Function that creates the map
    @param game game struct
    @param file string with name of file given to program
*/
void    map_creation(t_game game, char *file)
{
    char    *line;
    char    **map;
    int     fd;

    file_format(file);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        error("Couldn't open file", game);
    game.map.map = (char **)malloc(sizeof(game.map.map) * (n_lines(fd) + 2));
	if (game.map.map == NULL)
		return (NULL);
    game.map.rows = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        game.map.map[game.map.rows++] = line;
        free(line);
    }
    game.map.map[game.map.rows] = 0;
}