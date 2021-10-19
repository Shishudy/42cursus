/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:04:20 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:04:22 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, int len)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	if (*little == '\0')
		return (big);
	while (k != len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0')
		{
			if (little[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
		k++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char *big = "Eu sou aluno da 42";
	char *little = "36";
	printf("%s ", ft_strnstr(big, little, 20));
	printf("%s\n", strnstr(big, little, 20));
}*/