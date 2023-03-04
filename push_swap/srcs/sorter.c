/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:20:37 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/03 17:56:32 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	if ((*a)->x > (*a)->next->x && (*a)->x > temp->x &&
	 (*a)->next->x < temp->x)
		ra(a);
	else if ((*a)->x > (*a)->next->x && (*a)->x > temp->x &&
	 (*a)->next->x > temp->x)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->x > (*a)->next->x && (*a)->x < temp->x)
		sa(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x > temp->x)
		rra(a);
	else if ((*a)->x < (*a)->next->x && (*a)->x < temp->x)
	{
		sa(a);
		ra(a);
	}
}

void	sort_5(t_list **a, t_list **b)
{
	int	meio;
	int	pnultimo;

	meio = ft_meio(a);
	pnultimo = ft_pultimo(a);
	while (cnt_recursive(*a) != 3)
 		send_desire(a, b, meio, pnultimo);
	if (!list_sorted(a))
		sort_3_elements(a);
	if ((*b)->x < (*b)->next->x)
		sb(b);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
	pa(a, b);
	if (!(list_sorted(a)))
		sa(a);
}

void	sort_biggest(t_list **a, t_list **b)
{
	t_list	*temp;

	while (cnt_recursive(*a) != 0)
		best_move(a, b, start(a), end(a));
	while (cnt_recursive(*b) > 15)
	{
		temp = (*b);
		while (temp->next != NULL)
			temp = temp->next;
		if ((*b)->x > temp->x)
			send_top_b(a, b);
		else if ((*b)->x < temp->x)
			send_bot_b(a, b);
	}
	send_rest(a, b);
}