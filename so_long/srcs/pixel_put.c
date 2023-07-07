/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:54 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 18:08:08 by rasantos         ###   ########.fr       */
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
