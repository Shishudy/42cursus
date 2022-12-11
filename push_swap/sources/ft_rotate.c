/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:28 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/05 18:04:28 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_rotate(char **stack, int )
{
	int		i;
	char	**temp;
	
	i = 0;
	temp[i++] = stack[last];
	while (i + 1 < last)
	{
		temp[i] = stack[i + 1];
	}
	temp[i] = stack[0];
	i = 0;
	while (i < )
	{
		stack[i] = temp[i++];
	}

}