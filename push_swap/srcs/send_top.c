/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:44:58 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/07 10:47:38 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_small(t_list *b)
{
	t_list	*temp;
	t_list	*last;
	int		small;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	small = temp->x;
	while (temp->x > last->x)
	{
		if (small > temp->x)
			small = temp->x;
		temp = temp->next;
	}
	return (small);
}

int	top_big(t_list *b)
{
	t_list	*temp;
	t_list	*last;
	int		big;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	big = temp->x;
	while (temp->x > last->x)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
	}
	return (big);
}

void	part_send_top(t_list **a, t_list **b, t_list *last, int n)
{
	int	i;

	i = 0;
	while ((*b)->x > last->x)
	{
		pa(a, b);
		if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x)
			sa(a);
		i++;
	}
	i = i + n;
	while (n-- != 0)
	{
		rrb(b);
		pa(a, b);
		if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x)
			sa(a);
	}
	sort_a(a, b, i);
}

void	send_top_b(t_list **a, t_list **b)
{
	t_list	*last;
	t_mid	use;
	int		r;

	last = *b;
	while (last->next != NULL)
		last = last->next;
	use.md_pnt = md_chunk(b, top_small(*b), top_big(*b));
	use.i = 0;
	use.n = 0;
	r = n_midpoint(b, use.md_pnt, top_big(*b));
	while (r != 0)
	{
		if ((*b)->x >= use.md_pnt && ++use.i && r--)
		{
			pa(a, b);
			if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x)
				sa(a);
		}
		else if ((*b)->x < use.md_pnt && ++use.n)
			rb(b);
	}
	sort_a(a, b, use.i);
	part_send_top(a, b, last, use.n);
}
