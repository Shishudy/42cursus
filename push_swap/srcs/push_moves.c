/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:06:08 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/23 20:39:23 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **s_b, t_list **s_a)
{
	t_list	*s_stack_a;
	t_list	*s_stack_b;

	s_stack_a = &s_a;
	s_stack_b = &s_b;
	ft_lstadd_front(&s_stack_a, s_stack_b->content);
	ft_printf("%s\n", "pa");
}

void	pb(t_list **s_a, t_list **s_b)
{
	t_list	*s_stack_a;
	t_list	*s_stack_b;

	s_stack_a = &s_a;
	s_stack_b = &s_b;
	ft_lstadd_front(&s_stack_b, s_stack_a->content);
	ft_printf("%s\n", "pb");
}