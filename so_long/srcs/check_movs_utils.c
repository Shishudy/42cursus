/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:38:35 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/26 15:59:16 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

int	check_collectible(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == 'C')
	{
		game->map.keys--;
		game->map.map[(int)y][(int)x] = '0';
		clear_player_image(game, (int)x, (int)y);
		return (0);
	}
	return (1);
}

int	check_exit(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == 'E' && game->map.keys <= 0)
		return (1);
	return (0);
}
