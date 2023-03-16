/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:29:16 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/15 20:59:17 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	char			**map;
    int             cols; 			// x
	int				rows;    		// y
	int				enemies;
	int				collectibles;
	int				exit;
	int				player;
}					t_map;

typedef struct s_images
{

}					t_images;

typedef struct s_player
{
	int				x,y;

}					t_player;

typedef struct s_enemies
{
	int				x,y;

}					t_enemies;

typedef struct s_game
{
    t_map       	map;
	t_images		wall;
	t_images		floor;
	t_images		floor2;
	t_images		exit;
	t_images		collectibles;
	t_images		player;
	t_images		enemies;
}               t_game;

void    map_creation(t_game game, char *file);
void    map_check(char **map);

#endif
