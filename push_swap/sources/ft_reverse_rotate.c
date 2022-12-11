/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:10 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/05 18:04:10 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_reverse_rotate(char **stack, int )
{
	int		i;
	char	**temp;
	
	i = 0;
	temp[i] = stack[last];
	while (i + 1 < last)
	{
		temp[i + 1] = stack[i++];
	}
	i = 0;
	while (i < last)
	{
		stack[i] = temp[i++];
	}

}