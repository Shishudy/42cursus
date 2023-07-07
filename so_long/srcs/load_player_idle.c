/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_idle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:26:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/04/11 21:17:03 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_xpm(t_game *game, char *filename, t_img *mem)
{
    mem->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, filename, &mem->w, &mem->h);
    mem->addr = mlx_get_data_addr(mem->img_ptr, &mem->bpp, &mem->size_line, &mem->endian);
}

void    player_idle_up(t_game *game)
{
    load_xpm(game, "images/i_u1", &game->map.player.i_u[0]);
    load_xpm(game, "images/i_u2", &game->map.player.i_u[1]);
    load_xpm(game, "images/i_u3", &game->map.player.i_u[2]);
    load_xpm(game, "images/i_u4", &game->map.player.i_u[3]);
    load_xpm(game, "images/i_u5", &game->map.player.i_u[4]);
    load_xpm(game, "images/i_u6", &game->map.player.i_u[5]);
}

void    player_idle_down(t_game *game)
{
    load_xpm(game, "images/i_d1", &game->map.player.i_d[0]);
    load_xpm(game, "images/i_d2", &game->map.player.i_d[1]);
    load_xpm(game, "images/i_d3", &game->map.player.i_d[2]);
    load_xpm(game, "images/i_d4", &game->map.player.i_d[3]);
    load_xpm(game, "images/i_d5", &game->map.player.i_d[4]);
    load_xpm(game, "images/i_d6", &game->map.player.i_d[5]);
}

void    player_idle_left(t_game *game)
{
    load_xpm(game, "images/i_l1", &game->map.player.i_l[0]);
    load_xpm(game, "images/i_l2", &game->map.player.i_l[1]);
    load_xpm(game, "images/i_l3", &game->map.player.i_l[2]);
    load_xpm(game, "images/i_l4", &game->map.player.i_l[3]);
    load_xpm(game, "images/i_l5", &game->map.player.i_l[4]);
    load_xpm(game, "images/i_l6", &game->map.player.i_l[5]);
}

void    player_idle_right(t_game *game)
{
    load_xpm(game, "images/i_r1", &game->map.player.i_r[0]);
    load_xpm(game, "images/i_r2", &game->map.player.i_r[1]);
    load_xpm(game, "images/i_r3", &game->map.player.i_r[2]);
    load_xpm(game, "images/i_r4", &game->map.player.i_r[3]);
    load_xpm(game, "images/i_r5", &game->map.player.i_r[4]);
    load_xpm(game, "images/i_r6", &game->map.player.i_r[5]);
}

void    init_player_idle(t_game *game)
{
    player_idle_up(game);
    player_idle_down(game);
    player_idle_left(game);
    player_idle_right(game);
}