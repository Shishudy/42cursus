/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:21:47 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 19:33:08 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_run_up(t_game *game)
{
	load_xpm(game, "images/r_u1", &game->map.player.r_u[0]);
	load_xpm(game, "images/r_u2", &game->map.player.r_u[1]);
	load_xpm(game, "images/r_u3", &game->map.player.r_u[2]);
	load_xpm(game, "images/r_u4", &game->map.player.r_u[3]);
	load_xpm(game, "images/r_u5", &game->map.player.r_u[4]);
	load_xpm(game, "images/r_u6", &game->map.player.r_u[5]);
}

void	player_run_down(t_game *game)
{
	load_xpm(game, "images/r_d1", &game->map.player.r_d[0]);
	load_xpm(game, "images/r_d2", &game->map.player.r_d[1]);
	load_xpm(game, "images/r_d3", &game->map.player.r_d[2]);
	load_xpm(game, "images/r_d4", &game->map.player.r_d[3]);
	load_xpm(game, "images/r_d5", &game->map.player.r_d[4]);
	load_xpm(game, "images/r_d6", &game->map.player.r_d[5]);
}

void	player_run_left(t_game *game)
{
	load_xpm(game, "images/r_l1", &game->map.player.r_l[0]);
	load_xpm(game, "images/r_l2", &game->map.player.r_l[1]);
	load_xpm(game, "images/r_l3", &game->map.player.r_l[2]);
	load_xpm(game, "images/r_l4", &game->map.player.r_l[3]);
	load_xpm(game, "images/r_l5", &game->map.player.r_l[4]);
	load_xpm(game, "images/r_l6", &game->map.player.r_l[5]);
}

void	player_run_right(t_game *game)
{
	load_xpm(game, "images/r_r1", &game->map.player.r_r[0]);
	load_xpm(game, "images/r_r2", &game->map.player.r_r[1]);
	load_xpm(game, "images/r_r3", &game->map.player.r_r[2]);
	load_xpm(game, "images/r_r4", &game->map.player.r_r[3]);
	load_xpm(game, "images/r_r5", &game->map.player.r_r[4]);
	load_xpm(game, "images/r_r6", &game->map.player.r_r[5]);
}

void	init_player_run(t_game *game)
{
	player_run_up(game);
	player_run_down(game);
	player_run_left(game);
	player_run_right(game);
}
