/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:39:27 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/16 15:39:27 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_free(char *s)
{
	free (s);
	s = NULL;
}

int	ft_putudec(unsigned int n)
{
	char			*s;
	int				len;
	unsigned int	nb;

	nb = n;
	if (nb == 0)
		return (ft_putchar('0'));
	len = ft_counter(nb);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (0);
	s[len--] = '\0';
	while (nb != 0)
	{
		s[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	len = ft_putstr(s);
	ft_free(s);
	return (len);
}
