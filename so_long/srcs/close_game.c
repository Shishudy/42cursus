/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:45:10 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/26 16:00:22 by rasantos         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx_ptr, game->exit[0].img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit[1].img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->keys.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
}

int	free_mem(t_game *game)
{
	int	i;

	clean_images_player(game);
	clean_images_rest(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	i = 0;
	while (i < game->map.rows)
		free(game->map.map[i++]);
	free(game->map.map);
	exit(ft_printf("%s\n", "Game closed!"));
	return (0);
}

int	close_game(int i, t_game *game)
{
	if (i == 0)
		ft_printf("%s\n", "You died!");
	else if (i == 1)
		ft_printf("%s\n", "You won!");
	free_mem(game);
	return (0);
}
