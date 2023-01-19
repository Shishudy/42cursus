/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:38:37 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/19 16:52:44 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Atoi modificado para apenas funcionar com int - push_swap
int	ft_atoi(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			return (n * sign);
		n = n * 10 + *str - '0';
		++str;
	}
	if (n > 2147483647 || n < -2147483648)
		exit (ft_printf("%s\n", "Error"));
	return (n * sign);
}
