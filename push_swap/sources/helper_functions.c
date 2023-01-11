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