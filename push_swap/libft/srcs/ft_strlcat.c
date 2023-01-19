/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:03:39 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:03:40 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	i = 0;
	while (dst[a])
		a++;
	while (src[b])
		b++;
	if (dstsize == 0)
		return (b);
	if (dstsize <= a)
		return (dstsize + b);
	while (dstsize && i < (dstsize - a - 1) && src[i])
	{
		dst[a + i] = src[i];
		i++;
	}
	dst[a + i] = '\0';
	return (b + a);
}
