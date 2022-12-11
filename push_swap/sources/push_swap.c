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
	int		j;
	char	*stack_a[argc - 1];
	char	*stack_b[argc - 1];

	if (push_swap_errors(argc, argv) == 0)
		return (0);
	while (j < argc)
		stack_a[j] = argv[j++];
	push_swap_sorter(stack_a, stack_b, argc - 1);
}