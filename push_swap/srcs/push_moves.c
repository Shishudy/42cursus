/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:06:08 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 18:10:23 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*curr;

	if (!*b)
		return ;
	curr = *b;
	*b = curr->next;
	curr->next = *a;
	*a = curr;
	ft_printf("%s\n", "pa");
}

void	pb(t_list **b, t_list **a)
{
	t_list	*curr;

	if (!*a)
		return ;
	curr = *a;
	*a = curr->next;
	curr->next = *b;
	*b = curr;
	ft_printf("%s\n", "pb");
}
