/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:25:11 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/04 16:25:11 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int push_swap_errors(int argc, char *argv[])
{
	int i;
	int j;
	int *arg;

	while (arg[i])
	{
		if (arg[i] > 2147483647 || arg[i] < -2147483648)
		{
			ft_printf("%s\n", "Error: parameters are bigger than an integer!");
			return (1);
		}
		j = 1;
		while (i + j < argc - 1)
		{
			if (arg[i + j] == arg[i])
			{
				ft_printf("%s\n", "Error: duplicate integers!");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (arg);
}