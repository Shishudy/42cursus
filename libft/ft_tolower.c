/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:04:58 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:05:00 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	i;

	i = 0;
	while (i != 257)
	{
		printf("%c ", ft_tolower(i));
		printf("%c\n", tolower(i));
		i++;
	}
}*/