/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:04:45 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:04:46 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *big, int little)
{
	int	i;

	i = 0;
	while (big[i] != '\0')
		i++;
	while (i != 0)
	{
		if (big[i] == little)
			return (&big[i]);
		i--;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char *big = "Eu sou aluno da 42";
	int little = 'u';
	printf("%s ", ft_strrchr(big, little));
	printf("%s\n", strrchr(big, little));
}*/