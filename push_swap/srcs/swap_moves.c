/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:13 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/23 19:26:32 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list s_a)
{
	t_list	*s_stack_a;
	t_list	*temp;

	s_stack_a = &s_a;
	temp = ft_lstnew(s_stack_a->content);
	s_stack_a->content = s_stack_a->next->content;
	s_stack_a->next->content = temp->content;
	ft_printf("%s\n", "sa");
}

void	sb(t_list s_b)
{
	t_list	*s_stack_b;
	t_list	*temp;

	s_stack_b = &s_b;
	temp = ft_lstnew(s_stack_b->content);
	s_stack_b->content = s_stack_b->next->content;
	s_stack_b->next->content = temp->content;
	ft_printf("%s\n", "sb");
}

void	ss(t_list s_a, t_list s_b)
{
	sa(s_a);
	sb(s_b);
	ft_printf("%s\n", "ss");
}
