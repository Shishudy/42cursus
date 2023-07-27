/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:29:54 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/21 14:46:10 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *remainder, char *buf)
{
	unsigned int	i;
	unsigned int	k;
	char			*cstr;

	if (!remainder)
	{
		remainder = malloc(sizeof(char) * 1);
		remainder[0] = '\0';
	}
	if (!remainder || !buf)
		return (NULL);
	cstr = malloc(sizeof(char) * (ft_strlen(remainder) + ft_strlen(buf) + 1));
	if (cstr == NULL)
		return (NULL);
	i = -1;
	k = -1;
	while (remainder[++i] != '\0')
		cstr[i] = remainder[i];
	while (buf[++k] != '\0')
		cstr[i + k] = buf[k];
	cstr[i + k] = '\0';
	free(remainder);
	return (cstr);
}
