/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:01:13 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:01:16 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void /**/ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
	//return (s);
}

/*#include <stdio.h>
int	main()
{
	char	b[50] = "Hi my name is";
	printf("%s ", ft_bzero(b, 8*sizeof(char)));
	printf("%s\n", bzero(b, 8*sizeof(char)));
}*/