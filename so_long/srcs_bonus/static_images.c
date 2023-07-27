/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:48:07 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 18:06:51 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_static_images(t_game *game)
{
	t_canvas	i;

	i.i = -1;
	while (game->map.map[++i.i])
	{
		i.j = -1;
		while (game->map.map[i.i][++i.j])
		{
			if (game->map.map[i.i][i.j] == '0')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
				game->floor.img_ptr, i.j * 32, i.i * 32);
			else if (game->map.map[i.i][i.j] == 'C')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
				game->keys.img_ptr, i.j * 32, i.i * 32);
			else if (game->map.map[i.i][i.j] == '1')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
				game->wall.img_ptr, i.j * 32, i.i * 32);
		}
	}
}

void	init_static_images(t_game *game)
{
	game->floor.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"images/floor", &game->floor.w, &game->floor.h);
	game->floor.addr = mlx_get_data_addr(game->floor.img_ptr, \
	&game->floor.bpp, &game->floor.size_line, &game->floor.endian);
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"images/wall", &game->wall.w, &game->wall.h);
	game->wall.addr = mlx_get_data_addr(game->wall.img_ptr, \
	&game->wall.bpp, &game->wall.size_line, &game->wall.endian);
	game->keys.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	"images/key", &game->keys.w, &game->keys.h);
	game->keys.addr = mlx_get_data_addr(game->keys.img_ptr, \
	&game->keys.bpp, &game->keys.size_line, &game->keys.endian);
}

void	init_canvas(t_game *game)
{
	init_static_images(game);
	put_static_images(game);
}
