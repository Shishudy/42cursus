/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:22:45 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 17:46:00 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_images_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx_ptr, game->map.player.i_u[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.i_d[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.i_l[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.i_r[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.r_u[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.r_d[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.r_l[i].img_ptr);
		mlx_destroy_image(game->mlx_ptr, game->map.player.r_r[i].img_ptr);
		i++;
	}
}

void	clean_images_rest(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
		mlx_destroy_image(game->mlx_ptr, game->map.enemy.r[i++].img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit[0].img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit[1].img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->keys.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
}

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
	if (i == 15000)
		enemy_control(game, n++);
	else if (i == 25000)
		enemy_control(game, n++);
	else if (i == 35000)
	{
		enemy_control(game, n++);
		i = 0;
	}
	if (n == 6)
		n = 0;
	if (game->map.player.idle != -1 && (i == 15000 || i == 25000 || i == 35000))
	{
		idle_player(game, ++game->map.player.idle, game->map.player.dir);
		if (game->map.player.idle == 5)
			game->map.player.idle = 0;
	}
	return (0);
}

void	free_mapserg(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.map[i++]);
	free(game->map.map);
}

int	close_game(int i, t_game *game)
{
	free_mapserg(game);
	clean_images_player(game);
	clean_images_rest(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	if (i == 0)
		exit(ft_printf("%s\n", "You died!"));
	else if (i == 1)
		exit(ft_printf("%s\n", "You won!"));
	return (0);
}

void	window_creation(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.cols * 32, game->map.rows * 32, "so_long");
	init_canvas(game);
	init_sprites(game);
	game->map.player.idle = 0;
	game->map.player.dir = 100;
	mlx_hook(game->win_ptr, 17, (1L << 17), close_game, game);
	mlx_hook(game->win_ptr, 2, (1L << 0), hooks, game);
	mlx_hook(game->win_ptr, 3, (1L << 1), idle, game);
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_loop(game->mlx_ptr);
}
