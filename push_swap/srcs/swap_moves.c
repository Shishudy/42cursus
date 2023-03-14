/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:13 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:04 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*second;

	if (!*a || cnt_rec(*a) <= 1)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	ft_printf("%s\n", "sa");
}

void	sb(t_list **b)
{
	t_list	*second;

	if (!*b || cnt_rec(*b) <= 1)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	ft_printf("%s\n", "sb");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_printf("%s\n", "ss");
}
