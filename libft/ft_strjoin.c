/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:42:00 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/08 16:42:01 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	clen;
	char			*cstr;

	clen = ft_strlen(s1) + ft_strlen(s2);
	cstr = (malloc(clen + 1));
	if (cstr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		cstr[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		cstr[i + k] = s2[k];
		k++;
	}
	cstr[i + k] = '\0';
	return (cstr);
}
