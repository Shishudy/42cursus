/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:35:07 by rasantos          #+#    #+#             */
/*   Updated: 2023/06/18 15:19:24 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game_struct(t_game *game)
{   
    game->map.keys = 0;
    game->map.exit = 0;
    game->map.torches = 0;
    game->map.player.player = 0;
    game->map.bad_guys = 0;
    game->map.player.run = 0;
}