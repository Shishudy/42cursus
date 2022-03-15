/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:43:33 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/08 16:43:36 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_checker(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*strim;
	unsigned int	strt;
	unsigned int	end;
	unsigned int	i;

	if (!*s1 || !*set)
		return (ft_strdup(s1));
	strt = 0;
	end = ft_strlen(s1);
	while (s1[strt] != '\0' && set_checker(s1[strt], set))
		strt++;
	while (set_checker(s1[end - 1], set) && strt < end)
		end--;
	strim = (char *)malloc(sizeof(char) * (end - strt + 1));
	if (strim == NULL)
		return (NULL);
	i = 0;
	while (strt < end)
		strim[i++] = s1[strt++];
	strim[i] = '\0';
	return (strim);
}
