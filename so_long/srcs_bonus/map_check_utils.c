/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/26 15:53:43 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		size++;
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**map_clone(char **map)
{
	char	**clone;
	int		i;

	i = 0;
	while (map[i])
		i++;
	clone = (char **)malloc((i + 1) * sizeof(*clone));
	if (!clone)
		exit(ft_printf("Error\n%s\n", "Malloc error in map_clone"));
	i = 0;
	while (map[i])
	{
		clone[i] = ft_strdup(map[i]);
		i++;
	}
	clone[i] = 0;
	return (clone);
}

int	path_checker(t_map clone, int x, int y, char c)
{
	if (clone.map[y][x] == c)
		clone.poi++;
	if (clone.map[y][x] == '1')
		return (clone.poi);
	if (clone.map[y][x] == 'B')
		return (clone.poi);
	clone.map[y][x] = '1';
	clone.poi = path_checker(clone, x - 1, y, c);
	clone.poi = path_checker(clone, x + 1, y, c);
	clone.poi = path_checker(clone, x, y - 1, c);
	clone.poi = path_checker(clone, x, y + 1, c);
	return (clone.poi);
}

void	chars_checker(char c, t_game *game)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && \
	c != 'P' && c != 'B' && c != '\n')
		error_messages("Unknown character in map", game);
}

void	chars_counter(char c, int i, int j, t_game *game)
{
	if (c == 'C')
		game->map.keys++;
	else if (c == 'P')
	{
		game->map.player.player++;
		game->map.player.x = j;
		game->map.player.y = i;
	}
	else if (c == 'E')
		game->map.exit++;
	else if (c == 'B')
	{
		game->map.bad_guys++;
		game->map.enemy.x = j;
		game->map.enemy.y = i;
	}
}
