/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:35:31 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/18 15:19:20 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnlstrjoin(char *remainder, char *buf)
{
	int		i;
	int		k;
	char	*str;

	if (!remainder)
	{
		remainder = malloc(sizeof(char) * 1);
		remainder[0] = '\0';
	}
	if (!remainder || !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(remainder) + ft_strlen(buf) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	k = -1;
	while (remainder[++i] != '\0')
		str[i] = remainder[i];
	while (buf[++k] != '\0')
		str[i + k] = buf[k];
	str[i + k] = '\0';
	free(remainder);
	return (str);
}
