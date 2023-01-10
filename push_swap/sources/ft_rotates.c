/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:09:52 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/10 14:09:52 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_reverse_rotate(int *stack)
{
	int	i;
	int	j;
	int	*temp;
	
	if (!stack)
		return (0);
	while (stack[j])
		j++;
	temp[0] = stack[j];
	i = 1;
	while (i < j)
	{
		temp[i] = stack[i - 1];
		i++;
	}
	return (temp);
}

int	*ft_rotate(int *stack, int argc)
{
	int	i;
	int	*temp;
	
	if (!stack)
		return (0);
	i = 0;
	while (stack[i + 1])
	{
		temp[i] = stack[i + 1];
		i++;
	}
	temp[i] = stack[0];
	return (temp);
}
