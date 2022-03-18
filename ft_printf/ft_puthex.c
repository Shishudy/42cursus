/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:24:45 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/17 14:24:46 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	ft_counter(long int nbr)
{
	int	i;

	i = 0;
	while (nbr >= 16)
	{
		i++;
		nbr = nbr / 16;
	}
	if (nbr < 16)
		i++;
	return (i);
}

static void	ft_free(char *s)
{
	free (s);
	s = NULL;
}

int	ft_puthex(long int nbr, int lu)
{
	char	*hexa;
	char	*s;
	int		i;

	if (lu == 0)
		hexa = "0123456789abcdef";
	else if (lu == 1)
		hexa = "0123456789ABCDEF";
	s = (char *)malloc(sizeof(char) * (ft_counter(nbr) + 1));
	if (s == NULL)
		return (0);
	i = 0;
	while (nbr >= 16)
	{
		s[i++] = hexa[nbr % 16];
		nbr = nbr / 16;
	}
	if (nbr < 16)
		s[i++] = hexa[nbr];
	s[i] = '\0';
	i = ft_putstr(s);
	ft_free(s);
	return (i);
}
