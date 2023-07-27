/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:54:38 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 19:55:57 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_messages(char *error, t_game *game)
{
	int	i;

	ft_printf("Error\n%s\n", error);
	i = 0;
	while (i < game->map.rows)
		free(game->map.map[i++]);
	free(game->map.map);
	exit(0);
}
