/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:00:59 by rasantos          #+#    #+#             */
/*   Updated: 2021/10/19 18:01:07 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

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
	return (n * sign);
}
