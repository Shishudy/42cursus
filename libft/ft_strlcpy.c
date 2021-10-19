/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:03:47 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:03:48 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (i < (size - 1) && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	while (*src)
	{
		src_len++;
		src++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*#include <string.h>
#include <stdio.h>

int main(void)
{
	const char src1[10]	= "ab4";
	char dest1[10]   = "12345";

	char src[10]	= "ab4";
	char dest[10]	= "12345";

	printf("Str: %ld\n", ft_strlcpy(dest, src, 6));
	printf("%s\n", dest);
	printf("Str: %ld \n", strlcpy(dest1, src1, 6));
	printf("%s\n", dest1);
	return (0);
}*/