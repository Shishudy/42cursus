/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:01:53 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:01:56 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/*#include <ctype.h>
#include <stdio.h>

int	main()
{
	int	i;

	i = 0;
	while (i != 257)
	{
		printf("%d", isascii(i));
		printf("%d\n", ft_isascii(i));
		i++;
	}
}*/
