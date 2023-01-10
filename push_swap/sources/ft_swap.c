/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:03:59 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/05 18:03:59 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_swap(int *stack, int argc)
{
	int	i;
	int	*temp;
	
	if (!stack || !stack[1])
		return (0);
	temp[0] = stack[1];
	temp[1] = stack[0];
	i = 2;
	while (i < argc - 1)
	{
		temp[i] = stack[i];
		i++;
	}
	return (temp);
}
