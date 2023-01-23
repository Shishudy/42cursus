/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:19:50 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/20 19:57:33 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list s_a)
{
	t_list	*s_stack_a;

	s_stack_a = &s_a;
	ft_lstadd_back(s_stack_a, s_stack_a->content);
	ft_printf("%s\n", "ra");
}

void	rb(t_list s_b)
{
	t_list	*s_stack_b;

	s_stack_b = &s_b;
	ft_lstadd_back(s_stack_b, s_stack_b->content);
	ft_printf("%s\n", "rb");
}

void	rr(t_list s_a, t_list s_b)
{
	ra(s_a);
	ra(s_b);
	ft_printf("%s\n", "rr");
}
