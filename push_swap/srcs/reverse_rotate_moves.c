/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:42:17 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:12 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*curr;
	t_list	*before_last;

	if (cnt_rec(*a) <= 1)
		return ;
	curr = *a;
	before_last = *a;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *a;
	*a = curr;
	before_last->next = NULL;
	ft_printf("%s\n", "rra");
}

void	rrb(t_list **b)
{
	t_list	*curr;
	t_list	*before_last;

	if (cnt_rec(*b) <= 1)
		return ;
	curr = *b;
	before_last = *b;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *b;
	*b = curr;
	before_last->next = NULL;
	ft_printf("%s\n", "rrb");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("%s\n", "rrr");
}
