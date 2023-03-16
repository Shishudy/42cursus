/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:43:12 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/15 22:07:58 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_check(char **map)
{
    int i;
    int j;
    char    c;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            c = map[i][j];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
                exit(ft_printf("%s\n", "Unknown character in .ber file"));
        }

    }
}