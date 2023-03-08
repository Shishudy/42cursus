/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:55:13 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/08 11:38:40 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	if ((*a)->x > (*a)->next->x && (*a)->x > temp->x && (*a)->next->x < temp->x)
		ra(a);
	else if ((*a)->x > (*a)->next->x && (*a)->x > temp->x
		&& (*a)->next->x > temp->x)
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
	return ;
}

int	ft_pultimo(t_list **a)
{
	t_list	*list_temp;
	int		pultimo;

	list_temp = clone_list(a);
	sort_list(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&list_temp, 0);
	return (pultimo);
}

int	ft_meio(t_list **a)
{
	t_list	*list_temp;
	int		meio;

	list_temp = clone_list(a);
	sort_list(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&list_temp, 0);
	return (meio);
}

void	sort_5(t_list **a, t_list **b)
{
	int	meio;
	int	pnultimo;

	meio = ft_meio(a);
	pnultimo = ft_pultimo(a);
	while (cnt_rec(*a) != 3)
	{
		if ((*a)->x == meio || (*a)->x == pnultimo)
			ra(a);
		else
			pb(b, a);
	}
	if (!list_sorted(a))
		sort_3(a);
	if ((*b)->x < (*b)->next->x)
		sb(b);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
	pa(a, b);
	if (!(list_sorted(a)))
		sa(a);
}
