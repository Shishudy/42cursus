/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:28:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/07 17:43:50 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
		return (0);
	game.map = map_creation(argv[1]);
	init_game_struct(&game);
	game.map = map_check(game.map);
	window_creation(&game);
	return (0);
}
