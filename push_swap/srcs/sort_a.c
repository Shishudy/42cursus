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

	if (list_sorted(a))
		return ;
	i = n_control;
	while (n_control-- != 0 && !list_sorted(a))
		rra(a);
	if (i == 2 && !list_sorted(a))
		sa(a);
}

void	back_pb(t_list **a, t_list **b, int n_control)
{
	int	i;

	while (n_control-- != 0)
	{
		i = (*b)->x;
		if (i > (*a)->x && cnt_rec(*a) > 0)
		{
			pa(a, b);
			sa(a);
		}
		else
			pa(a, b);
	}
}

void	sort_rest_a(t_list **a, t_list **b, int ra_control, int pb_control)
{
	back_ra(a, ra_control);
	if (!(list_sorted(a)))
		sort_a(a, b, ra_control);
	back_pb(a, b, pb_control);
	if (!(list_sorted(a)))
		sort_a(a, b, pb_control);
}

void	sort_a(t_list **a, t_list **b, int n_moviments)
{
	int	mid_pnt;
	int	ra_control;
	int	pb_control;

	ra_control = 0;
	pb_control = 0;
	if (list_sorted(a))
		return ;
	mid_pnt = md_chunk(a, sort_a_small(a), sort_a_big(a, n_moviments));
	while (n_moviments-- >= 1)
	{
		if ((*a)->x >= mid_pnt && !list_sorted(a))
		{
			ra(a);
			ra_control++;
			if (list_sorted(a))
				ra_control--;
		}
		else if ((*a)->x < mid_pnt)
		{
			pb(b, a);
			pb_control++;
		}
	}
	sort_rest_a(a, b, ra_control, pb_control);
}
