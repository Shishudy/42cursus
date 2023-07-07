/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:01:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 18:29:05 by rasantos         ###   ########.fr       */
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
		exit(ft_printf("%s\n", "Malloc error in map_clone"));
	i = 0;
	while (map[i])
	{
		clone[i] = ft_strdup(map[i]);
		i++;
	}
	clone[i] = 0;
	return (clone);
}

int	path_checker(t_map clone, int x, int y, char c, int poi)
{
	if (clone.map[y][x] == c)
		poi++;
	if (clone.map[y][x] == '1')
		return (poi);
	if (clone.map[y][x] == 'B')
		return (poi);
	clone.map[y][x] = '1';
	poi = path_checker(clone, x - 1, y, c, poi);
	poi = path_checker(clone, x + 1, y, c, poi);
	poi = path_checker(clone, x, y - 1, c, poi);
	poi = path_checker(clone, x, y + 1, c, poi);
	return (poi);
}
