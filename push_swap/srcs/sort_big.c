/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:11:53 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/09 20:37:59 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_midpoint(t_list **root, int start, int end)
{
	t_list	*clone;
	t_list	*temp;
	int		i;

	if (start == end)
		return (1);
	clone = clone_list(root);
	temp = clone;
	sort_list(&temp);
	i = 1;
	while (temp->x != start)
		temp = temp->next;
	while (temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	deallocate(&clone, 0);
	return (i);
}

int	give_big(t_list **b)
{
	t_list	*last;
	int		big;

	last = (*b);
	big = last->x;
	while (last != NULL)
	{
		if (big < last->x)
			big = last->x;
		last = last->next;
	}
	return (big);
}

int	give_small(t_list **b)
{
	t_list	*last;
	int		small;

	last = (*b);
	small = last->x;
	while (last != NULL)
	{
		if (small > last->x)
			small = last->x;
		last = last->next;
	}
	return (small);
}

void	send_rest(t_list **a, t_list **b)
{
	int	md_pnt;
	int	big;
	int	i;
	int	n_movs;

	big = give_big(b);
	md_pnt = md_chunk(b, md_chunk(b, give_small(b), big), big);
	n_movs = n_midpoint(b, md_pnt, big);
	i = 0;
	while (n_movs != 0)
	{
		if ((*b)->x >= md_pnt)
		{
			pa(a, b);
			i++;
			n_movs--;
			if (cnt_rec(*a) > 1 && (*a)->x > (*a)->next->x && (*a)->x != big)
				sa(a);
		}
		else if ((*b)->x < md_pnt)
			rb(b);
	}
	sort_a(a, b, i);
	if (cnt_rec(*b) > 0)
		send_rest(a, b);
}

void	sort_biggest(t_list **a, t_list **b)
{
	t_list	*temp;

	while (cnt_rec(*a) != 0)
		best_move(a, b, start(a), end(a));
	while (cnt_rec(*b) > 30)
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
