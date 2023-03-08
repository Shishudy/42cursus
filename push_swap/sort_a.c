/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:48:32 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/08 10:22:32 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_ra(t_list **a, int n_control)
{
	int	i;

	i = n_control;
	if (cnt_rec(*a) <= 2 && list_sorted(a))
		return ;
	while (n_control-- != 0)
		rra(a);
	if (i == 2 && !list_sorted(a))
		sa(a);
}

void	back_pb(t_list **a, t_list **b, int n_control)
{
	while (n_control-- != 0)
		pa(a, b);
}

int	sort_a_big(t_list **root, int n_moviments)
{
	t_list	*temp;
	int		biggest;

	temp = (*root);
	biggest = temp->x;
	while (--n_moviments > 0)
	{
		if (biggest < temp->next->x)
			biggest = temp->next->x;
		temp = temp->next;
	}
	return (biggest);
}

int	sort_a_small(t_list **root)
{
	t_list	*temp;
	int		smallest;

	temp = *root;
	smallest = 0;
	while (temp->next != NULL)
	{
		if (temp->x > temp->next->x)
			smallest = temp->next->x;
		temp = temp->next;
	}
	return (smallest);
}

void	sort_a(t_list **a, t_list **b, int n_movs)
{
	int	mid_pnt;
	int	ra_control;
	int	pb_control;

	ra_control = 0;
	pb_control = 0;
	if (list_sorted(a))
		return ;
	mid_pnt = md_chunk(a, sort_a_small(a), sort_a_big(a, n_movs));
	while (n_movs-- >= 1)
	{
		if ((*a)->x >= mid_pnt && ++ra_control && !list_sorted(a))
			ra(a);
		else if ((*a)->x < mid_pnt && ++pb_control)
			pb(b, a);
	}
	back_ra(a, ra_control);
	if (!(list_sorted(a)))
		sort_a(a, b, ra_control);
	back_pb(a, b, pb_control);
	if (!(list_sorted(a)))
		sort_a(a, b, pb_control);
}
