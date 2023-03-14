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
	t_list	*clone;
	int		pultimo;

	clone = clone_list(a);
	list_temp = clone;
	sort_list(&list_temp);
	pultimo = list_temp->next->next->next->x;
	deallocate(&clone, 0);
	return (pultimo);
}

int	ft_meio(t_list **a)
{
	t_list	*list_temp;
	t_list	*clone;
	int		meio;

	clone = clone_list(a);
	list_temp = clone;
	sort_list(&list_temp);
	meio = list_temp->next->next->x;
	deallocate(&clone, 0);
	return (meio);
}

void	sort_4(t_list **a, t_list **b)
{
	if (small_i(a) == 0 || big_i(a) == 0)
		pb(b, a);
	else if (small_i(a) == 1 || big_i(a) == 1)
	{
		sa(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	else if (small_i(a) == 3 || big_i(a) == 3)
	{
		rra(a);
		if (list_sorted(a))
			return ;
		pb(b, a);
	}
	sort_3(a);
	pa(a, b);
	if (!(list_sorted(a)))
		ra(a);
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
