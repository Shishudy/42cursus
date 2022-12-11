/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:14:40 by rasantos          #+#    #+#             */
/*   Updated: 2022/03/08 18:14:41 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n2;

	n2 = n;
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
	else if (n2 >= 0 && n2 < 10)
		ft_putchar_fd(n2 + '0', fd);
	else if (n2 < 0 && n2 > -10)
	{
		n2 = -n2;
		ft_putchar_fd('-', fd);
		ft_putchar_fd(n2 + '0', fd);
	}
	else
	{
		n2 = -n2;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n2 / 10, fd);
		ft_putnbr_fd(n2 % 10, fd);
	}
}
