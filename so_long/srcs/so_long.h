/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:29:16 by rasantos          #+#    #+#             */
/*   Updated: 2023/06/18 15:16:14 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_img
{
	int				w;
	int				h;
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_player
{
	double			x;
	double			y;
	int				idle;
	int				run;
	int				dir;
	int				player;
	t_img			i_u[6];
	t_img			i_d[6];
	t_img			i_l[6];
	t_img			i_r[6];
	t_img			r_u[6];
	t_img			r_d[6];
	t_img			r_l[6];
	t_img			r_r[6];
}					t_player;

typedef struct s_enemy
{
	double			x;
	double			y;
	int				i;
	t_img			r[6];
}					t_enemy;

typedef struct s_map
{
	char			**map;
    int             cols; 			// x
	int				rows;    		// y
	int				bad_guys;
	int				exit;
	int				keys;
	int				torches;
	t_player		player;
	t_enemy			enemy;
}					t_map;


typedef struct s_canvas
{
	int				x;
	int				y;
	int				i;
	int				j;
}					t_canvas;

typedef struct s_game
{
	int				time;
	void			*mlx_ptr;
	void			*win_ptr;
    t_map       	map;
	t_img			wall;
	t_img			floor;
	t_img			exit[2];
	t_img			keys;
	t_img			torch[3];
}               	t_game;

int		check_walls(t_game *game, double x, double y);
int		check_enemy2(t_game *game, double x, double y);
int		check_collectible(t_game *game, double x, double y);
int		check_exit(t_game *game, double x, double y);
int		close_game(int i, t_game *game);
void	init_enemy(t_game *game);
void    enemy_control(t_game *game, int n);
void    put_moving_images(t_game *game, t_img img, char c);
void    load_xpm(t_game *game, char *filename, t_img *mem);
void	put_image(t_game *game, t_img img, double x, double y);
int 	check_up(t_game *game, double x, double y);
int 	check_left(t_game *game, double x, double y);
int 	check_down(t_game *game, double x, double y);
int 	check_right(t_game *game, double x, double y);
void    clear_player_image(t_game *game, int x, int y);
void	idle_player(t_game *game, int i, int last);
void    init_player_run(t_game *game);
void    init_player_idle(t_game *game);
void    move_up(t_game *game, int i);
void    move_left(t_game *game, int i);
void    move_down(t_game *game, int i);
void    move_right(t_game *game, int i);
int		hooks(int keycode, t_game *game);
void	init_sprites(t_game *game);
void    init_floors(t_game *game);
void    init_walls(t_game *game);
int 	pixel_color(t_img *img, int x, int y);
void    init_canvas(t_game *game);
void    init_static_images(t_game *game);
void	init_game_struct(t_game *game);
t_map	map_creation(char *file);
t_map	map_check(t_map map);
char    **map_clone(char **map);
int		path_checker(t_map clone, int x, int y, char c, int poi);
void    window_creation(t_game *game);

#endif
