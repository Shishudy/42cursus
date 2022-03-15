/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:01:23 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:01:24 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	s;
	char			*m;

	s = count * size;
	m = malloc(s);
	if (m == NULL)
		return (NULL);
	ft_memset(m, 0, s);
	return (m);
}
