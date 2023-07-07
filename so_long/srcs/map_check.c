/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:43:12 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 18:29:22 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    wall_check(t_map map)
{
    int i;

    i = 0;
    while (i != map.cols)
    {
        if (map.map[0][i] != '1')
            exit(ft_printf("%s\n", "Map not closed TOP"));
        if (map.map[map.rows - 1][i] != '1')
            exit(ft_printf("%s\n", "Map not closed BOT"));
        i++;
    }
    i = 0;
    while (i != map.rows - 1)
    {
        if (map.map[i][0] != '1')
            exit(ft_printf("%s\n", "Map not closed LEFT"));
        if (map.map[i][map.cols - 1] != '1')
            exit(ft_printf("%s\n", "Map not closed RIGHT"));
        i++;
    }
}

void    dup_check(t_map *map)
{
    int     i;
    int     j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (j != map->cols + 1)
        {
            if (map->map[i][j] == 'C')
                map->keys++;
            if (map->map[i][j] == 'P')
            {
                map->player.player++;
                map->player.x = j;
                map->player.y = i;
            }
            if (map->map[i][j] == 'E')
                map->exit++;
            if (map->map[i][j] == 'B')
            {
                map->bad_guys++;
                map->enemy.x = j;
                map->enemy.y = i;
            }
            j++;
        }
        i++;
    }
    if (map->player.player != 1 || map->exit != 1)
        exit(ft_printf("%s\n", "Duplicates in map"));
}

void    free_map(t_map clone)
{
    int i;

    i = 0;
    while (clone.map[i])
    {
        free(clone.map[i]);
        i++;
    }
    free(clone.map);
}

void	path_check(t_map map)
{
	static t_map	clone;
	int				poi;

    clone.map = map_clone(map.map);
    poi = 0;
    poi = path_checker(clone, map.player.x, map.player.y, 'C', poi);
    if (poi != map.keys)
        exit(ft_printf("%s\n", "Map doesn't have a valid path"));
    free_map(clone);
    clone.map = map_clone(map.map);
    poi = 0;
    poi = path_checker(clone, map.player.x, map.player.y, 'E', poi);
    if (poi != map.exit)
        exit(ft_printf("%s\n", "Map doesn't have a valid path"));
    free_map(clone);
}

t_map   map_check(t_map map)
{
    char    c;
    int     i;
    int     j;

    map.cols = ft_strlen(map.map[map.rows - 1]);
    if (map.cols == 0)
        exit(ft_printf("%s\n", "Map is empty"));
    i = 0;
    while (map.map[i])
    {
        if (map.cols != (int)ft_strlen(map.map[i]) - 1 && i != map.rows - 1)
            exit(ft_printf("%s\n", "Map isn't rectangular"));
        j = 0;
        while (map.map[i][j] != '\0')
        {
            c = map.map[i][j];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != 'B' && c != '\n')
                exit(ft_printf("%s\n", "Unknown character in map"));
            j++;
        }
        i++;
    }
    wall_check(map);
    dup_check(&map);
    path_check(map);
    return (map);
}