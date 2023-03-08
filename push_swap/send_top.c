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

void	sort_back_top(t_list **a, t_list **b, int i, int n)
{
	sort_a(a, b, i);
	i = n;
	while (n-- != 0)
	{
		rrb(b);
		pa(a, b);
	}
	sort_a(a, b, i);
}

int		top_small(t_list *b)
{
	t_list *temp;
	t_list *last;
	int	small;
	int	i;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	small = temp->x ;
	i = 0;
	while (temp->x > last->x)
	{
		if (small > temp->x)
			small = temp->x;
		i++;
		temp = temp->next;
	}
	return (small);
}

int		top_big(t_list *b)
{
	t_list *temp;
	t_list *last;
	int	big;
	int	i;

	temp = b;
	last = b;
	while (last->next != NULL)
		last = last->next;
	big = temp->x;
	i = 0;
	while (temp->x > last->x)
	{
		if (big < temp->x)
			big = temp->x;
		temp = temp->next;
		i++;
	}
	return (big);
}

void	send_top_b(t_list **a, t_list **b)
{
	t_list *last;
	int	i;
	int	n;
	int	md_pnt;

	last = *b;
	while (last->next != NULL)
		last = last->next;
	md_pnt = md_chunk(b, top_small(*b), top_big(*b));
	i = 0;
	n = 0;
	while ((*b)->x > last->x)
	{
		if ((*b)->x >= md_pnt && ++i)
			pa(a, b);
		else if ((*b)->x < md_pnt && ++n)
			rb(b);
	}
	sort_back_top(a, b, i, n);
}