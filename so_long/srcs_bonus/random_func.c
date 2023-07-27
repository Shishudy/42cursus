/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:00 by rasantos          #+#    #+#             */
/*   Updated: 2023/07/25 20:26:03 by rasantos         ###   ########.fr       */
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
	game->map.enemy.x = 0;
	game->map.enemy.y = 0;
	game->map.bad_guys = 0;
	game->map.player.run = 0;
}

static int	ft_counter(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	len = ft_counter(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
