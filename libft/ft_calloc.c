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

#include <stdlib.h>
#include "libft.h"

void *calloc(size_t nelem, size_t elsize)
{
	unsigned int	s;
	char			*m;

	s = nelem * elsize;
	if ((m = malloc(s)) == NULL)
		return (NULL);
	ft_memset(m, 0, s);
	return (m);
}
