/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:00 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/26 16:57:23 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_xpm(t_game *game, char *filename, t_img *mem)
{
	mem->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, filename, \
	&mem->w, &mem->h);
	mem->addr = mlx_get_data_addr(mem->img_ptr, &mem->bpp, \
	&mem->size_line, &mem->endian);
}

void	init_game_struct(t_game *game)
{
	game->map.keys = 0;
	game->map.exit = 0;
	game->map.player.player = 0;
	game->map.player.run = 0;
}
