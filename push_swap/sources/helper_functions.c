/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:29:45 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/04 18:29:45 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, int argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("%i\n", argv[i]);
		i++;
	}
	return (0);
}
