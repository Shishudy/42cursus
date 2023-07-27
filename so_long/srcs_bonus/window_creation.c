/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:22:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 20:07:11 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	idle(int a, t_game *game)
{
	(void)a;
	game->map.player.idle = 0;
	return (0);
}

int	render(t_game *game)
{
	static int	i;
	static int	n;

	if (game->map.keys == 0)
	{
		put_moving_images(game, game->exit[1], 'E');
		game->map.keys = -1;
	}
	i++;
	if (game->map.player.idle != -1 && i == 15000)
	{
		idle_player(game, ++game->map.player.idle, game->map.player.dir);
		if (game->map.player.idle == 5)
			game->map.player.idle = 0;
	}
	if (i == 15000)
	{
		if (game->map.bad_guys > 0)
			enemy_control(game, n++);
		i = 0;
	}
	if (n == 6)
		n = 0;
	return (0);
}

void	window_creation(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.cols * 32, \
	game->map.rows * 32, "so_long");
	init_canvas(game);
	init_sprites(game);
	game->map.player.idle = 0;
	game->map.player.dir = 100;
	mlx_hook(game->win_ptr, 2, (1L << 0), hooks, game);
	mlx_hook(game->win_ptr, 17, (1L << 2), free_mem, game);
	mlx_hook(game->win_ptr, 3, (1L << 1), idle, game);
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_loop(game->mlx_ptr);
}
