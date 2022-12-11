/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:37:23 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/05 10:37:23 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_swap_sorter(stack_a, stack_b, argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 1;
		while (i + j < argc)
		{
			if (stack_a[i] > stack_a[i + j])
			{
				
			}
			j++;
		}
		i++;
	}
}