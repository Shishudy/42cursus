/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:14:14 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 17:50:48 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	idle_player(t_game *game, int i, int last)
{
	clear_player_image(game, game->map.player.x, game->map.player.y);
	clear_player_image(game, game->map.player.x, game->map.player.y + 0.74f);
	clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y);
	clear_player_image(game, game->map.player.x + 0.51f, \
	game->map.player.y + 0.74f);
	if (last == 119)
		put_image(game, game->map.player.i_u[i], \
		game->map.player.x, game->map.player.y);
	else if (last == 97)
		put_image(game, game->map.player.i_l[i], \
		game->map.player.x, game->map.player.y);
	else if (last == 115)
		put_image(game, game->map.player.i_d[i], \
		game->map.player.x, game->map.player.y);
	else if (last == 100)
		put_image(game, game->map.player.i_r[i], \
		game->map.player.x, game->map.player.y);
}

int	hooks(int keycode, t_game *game)
{
	game->map.player.dir = keycode;
	if (keycode == KEY_ESC)
		close_game(0, game);
	else if (keycode == KEY_W)
		move_up(game, ++game->map.player.run);
	else if (keycode == KEY_A)
		move_left(game, ++game->map.player.run);
	else if (keycode == KEY_S)
		move_down(game, ++game->map.player.run);
	else if (keycode == KEY_D)
		move_right(game, ++game->map.player.run);
	if (game->map.player.run == 5)
		game->map.player.run = 0;
	game->map.player.idle = -1;
	return (0);
}
