/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:32:11 by rasantos          #+#    #+#             */
/*   Updated: 2022/05/12 17:32:14 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(unsigned long nbr)
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

static char	*ft_invert(char *s, int i)
{
	char	*ns;
	int		j;

	ns = (char *)malloc(sizeof(char) * (i + 2));
	if (ns == NULL)
		return (0);
	j = 0;
	while (i != -1)
	{
		ns[j] = s[i];
		i--;
		j++;
	}
	ns[j] = '\0';
	return (ns);
}

int	ft_puthex2(unsigned long nbr, int lu)
{
	char	*hexa;
	char	*s;
	char	*ns;
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
	ns = ft_invert(s, i - 1); //encurtar isto
	i = ft_putstr(ns);
	ft_free(ns);
	ft_free(s);
	return (i);
}
