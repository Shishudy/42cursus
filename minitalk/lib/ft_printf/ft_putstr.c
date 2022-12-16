/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:26:01 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/16 17:26:05 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[a] != '\0')
	{
		write (1, &str[a], 1);
		a++;
	}
	return (a);
}
