/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:05:43 by rasantos          #+#    #+#             */
/*   Updated: 2023/06/06 18:09:16 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	load_xpm(game, "images/enemy1.xpm", &game->map.enemy.r[0]);
	load_xpm(game, "images/enemy2.xpm", &game->map.enemy.r[1]);
	load_xpm(game, "images/enemy3.xpm", &game->map.enemy.r[2]);
	load_xpm(game, "images/enemy4.xpm", &game->map.enemy.r[3]);
	load_xpm(game, "images/enemy5.xpm", &game->map.enemy.r[4]);
	load_xpm(game, "images/enemy6.xpm", &game->map.enemy.r[5]);
}

void    clear_enemy_image(t_game *game, int x, int y)
{
    if (x == (int)game->map.player.x && y == (int)game->map.player.y)
        return ;
    else if (game->map.map[y][x] != 'E' && game->map.map[y][x] != '1' && game->map.map[y][x] != 'C')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.img_ptr, x * 32, y * 32);
    else if (game->map.map[y][x] == 'E' && game->map.keys > 0)
        put_moving_images(game, game->exit[0], 'E');
    else if (game->map.map[y][x] == 'E')
        put_moving_images(game, game->exit[1], 'E');
    else if (game->map.map[y][x] == 'C')
        put_image(game, game->keys, x, y);
}

int	check_enemy(t_game *game, double x, double y)
{
    if (game->map.map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

void    enemy_control(t_game *game, int n)
{
	clear_enemy_image(game, game->map.enemy.x, game->map.enemy.y);
    clear_enemy_image(game, game->map.enemy.x, game->map.enemy.y + 0.74f);
    clear_enemy_image(game, game->map.enemy.x + 0.51f, game->map.enemy.y);
    clear_enemy_image(game, game->map.enemy.x + 0.51f, game->map.enemy.y + 0.74f);
    if ((game->map.player.y < game->map.enemy.y) && check_enemy(game, game->map.enemy.x, game->map.enemy.y - 0.15f))
        game->map.enemy.y = game->map.enemy.y - 0.15f;
    else if ((game->map.player.y > game->map.enemy.y) && check_enemy(game, game->map.enemy.x, game->map.enemy.y + 0.15f))
        game->map.enemy.y = game->map.enemy.y + 0.15f;
    if ((game->map.player.x < game->map.enemy.x) && check_enemy(game, game->map.enemy.x - 0.15f, game->map.enemy.y))
        game->map.enemy.x = game->map.enemy.x - 0.15f;
    else if ((game->map.player.x > game->map.enemy.x) && check_enemy(game, game->map.enemy.x + 0.15f, game->map.enemy.y))
        game->map.enemy.x = game->map.enemy.x + 0.15f;
    //mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->map.enemy.x * 32, game->map.enemy.y * 32, 0xFFFFFF);
    put_image(game, game->map.enemy.r[n], game->map.enemy.x, game->map.enemy.y);
    if (((game->map.enemy.y >= game->map.player.y) && (game->map.enemy.y <= game->map.player.y + 0.74f)) && ((game->map.enemy.x >= game->map.player.x) && (game->map.enemy.x <= game->map.player.x + 0.49f)))
        close_game(0, game);
}
