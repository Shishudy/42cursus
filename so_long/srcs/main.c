/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:28:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/15 20:58:40 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;
    void    *mlx_ptr;
    void    *win_ptr;

    map_creation(game, ++(*argv));
    map_check(game.map.map);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
    mlx_loop(mlx_ptr);
}