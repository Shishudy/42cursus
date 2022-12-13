/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:33:42 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/16 10:33:43 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ftype(const char f, va_list arg)
{
	if (f == '%')
		return (ft_putchar('%'));
	else if (f == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (f == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (f == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (f == 'u')
		return (ft_putudec(va_arg(arg, unsigned int)));
	else if (f == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), 0));
	else if (f == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), 1));
	else if (f == 'p')
		return (ft_putstr("0x") + ft_puthex2(va_arg(arg, unsigned long)));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	arg;
	int		i;
	int		n;

	va_start(arg, f);
	i = 0;
	n = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			i++;
			n = n + ft_ftype(f[i], arg);
		}
		else
			n = n + ft_putchar(f[i]);
		i++;
	}
	va_end(arg);
	return (n);
}
