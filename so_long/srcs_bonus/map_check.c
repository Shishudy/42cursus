/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:43:12 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 20:44:05 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i != game->map.cols)
	{
		if (game->map.map[0][i] != '1')
			error_messages("Map not closed TOP", game);
		if (game->map.map[game->map.rows - 1][i] != '1')
			error_messages("Map not closed BOT", game);
		i++;
	}
	i = 0;
	while (i != game->map.rows - 1)
	{
		if (game->map.map[i][0] != '1')
			error_messages("Map not closed LEFT", game);
		if (game->map.map[i][game->map.cols - 1] != '1')
			error_messages("Map not closed RIGHT", game);
		i++;
	}
}

void	dup_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (j != game->map.cols + 1)
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0' && \
			game->map.map[i][j] != '\0')
				chars_counter(game->map.map[i][j], i, j, game);
			j++;
		}
		i++;
	}
	if (game->map.player.player != 1 || game->map.exit != 1 || \
	game->map.keys < 1)
		error_messages("Invalid number of characters", game);
	if (game->map.bad_guys > 1)
		error_messages("Too many enemies for this difficulty!", game);
}

void	free_map(t_map clone)
{
	int	i;

	i = 0;
	while (clone.map[i])
	{
		free(clone.map[i]);
		i++;
	}
	free(clone.map);
}

void	path_check(t_game *game)
{
	static t_map	clone;

	clone.map = map_clone(game->map.map);
	clone.poi = 0;
	clone.poi = path_checker(clone, game->map.player.x, \
	game->map.player.y, 'C');
	free_map(clone);
	if (clone.poi != game->map.keys)
		error_messages("Map doesn't have a valid path", game);
	clone.map = map_clone(game->map.map);
	clone.poi = 0;
	clone.poi = path_checker(clone, game->map.player.x, \
	game->map.player.y, 'E');
	free_map(clone);
	if (clone.poi != game->map.exit)
		error_messages("Map doesn't have a valid path", game);
}

void	map_check(t_game *game)
{
	int		i;
	int		j;

	game->map.cols = ft_strlen(game->map.map[game->map.rows - 1]);
	if (game->map.cols == 0)
		error_messages("Map is empty", game);
	i = 0;
	while (game->map.map[i])
	{
		if (game->map.cols != (int)ft_strlen(game->map.map[i]) - 1 && \
		i != game->map.rows - 1)
			error_messages("Map isn't rectangular", game);
		j = 0;
		while (game->map.map[i][j] != '\0')
		{
			chars_checker(game->map.map[i][j], game);
			j++;
		}
		i++;
	}
	wall_check(game);
	dup_check(game);
	path_check(game);
}
