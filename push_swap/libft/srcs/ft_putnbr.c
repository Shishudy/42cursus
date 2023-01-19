/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:42:19 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/16 11:42:20 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
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

int	ft_putnbr(int nb)
{
	char	*s;
	int		len;

	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb == 0)
		return (ft_putchar('0'));
	len = ft_counter(nb);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (0);
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
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
