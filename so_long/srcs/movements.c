/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:50:29 by rasantos          #+#    #+#             */
/*   Updated: 2023/06/06 20:55:04 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    clear_player_image(t_game *game, int x, int y)
{
    if (game->map.map[y][x] != 'E' && game->map.map[y][x] != '1' && game->map.map[y][x] != 'C')
    {
        if (x == (int)game->map.enemy.x && y == (int)game->map.enemy.y)
            return ;
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.img_ptr, x * 32, y * 32);
    }
    if (game->map.map[y][x] == 'E' && game->map.keys > 0)
        put_moving_images(game, game->exit[0], 'E');
}

void    move_up(t_game *game, int i)
{
    if (!check_up(game, game->map.player.x, game->map.player.y))
        return ;
    clear_player_image(game, game->map.player.x, game->map.player.y);
    clear_player_image(game, game->map.player.x, game->map.player.y + 0.74f);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y + 0.74f);
    game->map.player.y = game->map.player.y - 0.25f;
    put_image(game, game->map.player.r_u[i], game->map.player.x, game->map.player.y);
    game->map.player.player++;
    ft_printf("Movimentos: %i\n", game->map.player.player - 1);
}

void    move_left(t_game *game, int i)
{
    if (!check_left(game, game->map.player.x, game->map.player.y))
        return ;
    clear_player_image(game, game->map.player.x, game->map.player.y);
    clear_player_image(game, game->map.player.x, game->map.player.y + 0.74f);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y + 0.74f);
    game->map.player.x = game->map.player.x - 0.25f;
    put_image(game, game->map.player.r_l[i], game->map.player.x, game->map.player.y);
    game->map.player.player++;
    ft_printf("Movimentos: %i\n", game->map.player.player - 1);
}

void    move_down(t_game *game, int i)
{
    if (!check_down(game, game->map.player.x, game->map.player.y))
        return ;
    clear_player_image(game, game->map.player.x, game->map.player.y);
    clear_player_image(game, game->map.player.x, game->map.player.y + 0.74f);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y + 0.74f);
    game->map.player.y = game->map.player.y + 0.25f;
    put_image(game, game->map.player.r_d[i], game->map.player.x, game->map.player.y);
    game->map.player.player++;
    ft_printf("Movimentos: %i\n", game->map.player.player - 1);
}

void    move_right(t_game *game, int i)
{
    if (!check_right(game, game->map.player.x, game->map.player.y))
        return ;
    clear_player_image(game, game->map.player.x, game->map.player.y);
    clear_player_image(game, game->map.player.x, game->map.player.y + 0.74f);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y);
    clear_player_image(game, game->map.player.x + 0.51f, game->map.player.y + 0.74f);
    game->map.player.x = game->map.player.x + 0.25f;
    put_image(game, game->map.player.r_r[i], game->map.player.x, game->map.player.y);
    game->map.player.player++;
    ft_printf("Movimentos: %i\n", game->map.player.player - 1);
}