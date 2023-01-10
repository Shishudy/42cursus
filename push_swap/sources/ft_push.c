/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:19 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/05 18:04:19 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_push(int *send_stack, int *receive_stack)
{
	int	i;
	int	*new_r_stack;

	if (!send_stack)
		return (0);
	new_r_stack[0] = send_stack[0];
	i = 1;
	while (receive_stack[i - 1])
	{
		new_r_stack[i] = receive_stack[i - 1];
		i++;
	}
	return (*new_r_stack);
}

int	*ft_pushed(int *send_stack)
{
	int	i;
	int	*new_s_stack;

	if (!send_stack)
		return (0);
	i = 0;
	while (send_stack[i + 1])
	{
		new_s_stack[i] = send_stack[i + 1];
		i++;
	}
	return (new_s_stack);
}
