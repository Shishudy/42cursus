/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:54 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 21:16:37 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *) dst);
}

void	put_image(t_game *game, t_img img, double x, double y)
{
	t_canvas	canvas;
	int			color;

	canvas.i = -1;
	while (++canvas.i != img.h)
	{
		canvas.j = -1;
		while (++canvas.j != img.w)
		{
			color = pixel_color(&img, canvas.j, canvas.i);
			if (color != (int)0xFF000000)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, \
				x * 32 + canvas.j, y * 32 + canvas.i, color);
		}
	}
}

void	put_steps_to_window(t_game *game)
{
	char	*steps;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall.img_ptr, (game->map.cols - 3) * 32, \
		(game->map.rows - 1) * 32);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall.img_ptr, (game->map.cols - 2) * 32, \
		(game->map.rows - 1) * 32);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall.img_ptr, (game->map.cols - 1) * 32, \
		(game->map.rows - 1) * 32);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (game->map.cols - 3) * 32.2, \
	(game->map.rows) * 31.15, 0xF51414, "Steps: ");
	steps = ft_itoa(game->map.player.player - 1);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (game->map.cols - 1) * 31.7, \
	(game->map.rows) * 31.15, 0xF51414, steps);
	ft_printf("Movimentos: %s\n", steps);
	free(steps);
}
