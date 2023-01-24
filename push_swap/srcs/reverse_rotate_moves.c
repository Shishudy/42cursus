/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:42:17 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/23 20:51:54 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list s_a)
{
	t_list	*s_stack_a;

	s_stack_a = &s_a;
	ft_lstadd_front(&s_stack_a, s_stack_a->content);
	ft_printf("%s\n", "rra");
}

void	rrb(t_list s_b)
{
	t_list	*s_stack_b;

	s_stack_b = &s_b;
	ft_lstadd_front(&s_stack_b, s_stack_b->content);
	ft_printf("%s\n", "rrb");
}

void	rrr(t_list s_a, t_list s_b)
{
	rra(s_a);
	rra(s_b);
	ft_printf("%s\n", "rrr");
}
