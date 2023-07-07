/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:24:28 by rasantos          #+#    #+#             */
/*   Updated: 2023/06/18 15:20:43 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_exit(t_game *game)
{
    load_xpm(game, "images/doorclosed.xpm", &game->exit[0]);
    load_xpm(game, "images/dooropen.xpm", &game->exit[1]);
}

void    init_torch(t_game *game)
{
    load_xpm(game, "images/torch1.xpm", &game->torch[0]);
    load_xpm(game, "images/torch2.xpm", &game->torch[1]);
    load_xpm(game, "images/torch3.xpm", &game->torch[2]);
}

void    put_moving_images(t_game *game, t_img img, char c)
{
    t_canvas    i;
    
    i.i = -1;
    while(game->map.map[++i.i])
    {
        i.j = -1;
        while (game->map.map[i.i][++i.j])
        {
            if (game->map.map[i.i][i.j] == c)
            {
                if (c == 'T')
                    mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
                	game->wall.img_ptr, i.j * 32, i.i * 32);
                else
                    mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
                    game->floor.img_ptr, i.j * 32, i.i * 32);   
                put_image(game, img, i.j, i.i);
            }
        }
    }
}

void    init_sprites(t_game *game)
{
    init_exit(game);
    init_player_idle(game);
    init_player_run(game);
    put_moving_images(game, game->exit[0], 'E');
    put_moving_images(game, game->map.player.i_r[0], 'P');
    if (game->map.torches > 0)
    {
        init_torch(game);
        put_moving_images(game, game->torch[0], 'T');
    }
    if (game->map.bad_guys > 0)
    {
        init_enemy(game);
	    put_moving_images(game, game->map.enemy.r[0], 'B');
    }
}