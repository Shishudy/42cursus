/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:02:44 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:02:45 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *a;
	unsigned const char *b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*a == *b && n - 1 != 0)
	{
		a++;
		b++;
		n--;
	}
	return (*a - *b);
}

/*#include <stdio.h>
int	main()
{
	char	a[] = "abcdef";
	char	b[] = "abcdef";
	printf("%d ", ft_memcmp(a, b, 3*sizeof(char)));
	printf("%d\n", memcmp(a, b, 3*sizeof(char)));
}*/
