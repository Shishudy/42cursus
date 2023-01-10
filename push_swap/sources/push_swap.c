/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:04:15 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/03 17:04:15 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_swap(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	stack_a = push_swap_errors(argc, argv);
	push_swap_sorter(stack_a, stack_b, argc - 1);
	return (0);
}