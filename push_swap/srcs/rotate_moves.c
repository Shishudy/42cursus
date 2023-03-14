/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:19:50 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:27 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*curr;
	t_list	*temp;

	if (!*a || cnt_rec(*a) <= 1)
		return ;
	curr = *a;
	temp = *a;
	*a = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	ft_printf("%s\n", "ra");
}

void	rb(t_list **b)
{
	t_list	*curr;
	t_list	*temp;

	if (!*b || cnt_rec(*b) <= 1)
		return ;
	curr = *b;
	temp = *b;
	*b = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	ft_printf("%s\n", "rb");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("%s\n", "rr");
}
