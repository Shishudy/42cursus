/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:15:35 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 20:17:34 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up(t_game *game, double x, double y)
{
	if (!check_walls(game, x, y - 0.01f) || \
	!check_walls(game, x + 0.26f, y - 0.01f))
		return (0);
	else if (!check_enemy(game, x, y - 0.01f) || \
	!check_enemy(game, x + 0.26f, y - 0.01f))
		close_game(0, game);
	else if (!check_collectible(game, x, y - 0.01f) || \
	!check_collectible(game, x + 0.26f, y - 0.01f))
		return (1);
	else if (check_exit(game, x, y - 0.01f) || \
	check_exit(game, x + 0.26f, y - 0.01f))
		close_game(1, game);
	return (1);
}

int	check_left(t_game *game, double x, double y)
{
	if (!check_walls(game, x - 0.01f, y) || \
	!check_walls(game, x - 0.01f, y + 0.74f))
		return (0);
	else if (!check_enemy(game, x - 0.01f, y) || \
	!check_enemy(game, x - 0.01f, y + 0.74f))
		close_game(0, game);
	else if (!check_collectible(game, x - 0.01f, y) || \
	!check_collectible(game, x - 0.01f, y + 0.74f))
		return (1);
	else if (check_exit(game, x - 0.01f, y) || \
	check_exit(game, x - 0.01f, y + 0.74f))
		close_game(1, game);
	return (1);
}

int	check_down(t_game *game, double x, double y)
{
	if (!check_walls(game, x, y + 0.76f) || \
	!check_walls(game, x + 0.26f, y + 0.76f))
		return (0);
	else if (!check_enemy(game, x, y + 0.76f) || \
	!check_enemy(game, x + 0.26f, y + 0.76f))
		close_game(0, game);
	else if (!check_collectible(game, x, y + 0.76f) || \
	!check_collectible(game, x + 0.26f, y + 0.76f))
		return (1);
	else if (check_exit(game, x, y + 0.76f) || \
	check_exit(game, x + 0.26f, y + 0.76f))
		close_game(1, game);
	return (1);
}

int	check_right(t_game *game, double x, double y)
{
	if (!check_walls(game, x + 0.51f, y) || \
	!check_walls(game, x + 0.51f, y + 0.74f))
		return (0);
	else if (!check_enemy(game, x + 0.51f, y) || \
	!check_enemy(game, x + 0.51f, y + 0.74f))
		close_game(0, game);
	else if (!check_collectible(game, x + 0.51f, y) || \
	!check_collectible(game, x + 0.51f, y + 0.74f))
		return (1);
	else if (check_exit(game, x + 0.51f, y) || \
	check_exit(game, x + 0.51f, y + 0.74f))
		close_game(1, game);
	return (1);
}
