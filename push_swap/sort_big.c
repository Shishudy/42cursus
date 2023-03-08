/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:11:53 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/08 10:24:51 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_midpoint(t_list **b, int midpoint, int end)
{
	t_list	*temp;
	int		i;

	temp = clone_list(b);
	sort_list(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != midpoint)
		temp = temp->next;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	send_rest(t_list **a, t_list **b)
{
	t_list	*last;
	int		md_pnt;
	int		small;
	int		big;
	int		i;
	int		n;
	int		flag;

	last = *b;
	small = last->x;
	big = last->x;
	n = 0;
	i = 0;
	while (last->next != NULL)
	{
		if (small > last->x)
			small = last->x;
		if (big < last->x)
			big = last->x;
		last = last->next;
	}
	md_pnt = md_chunk(b, small, big);
	while (flag == 0)
	{
		if ((*b)->x == last->x)
			flag = 1;
		if ((*b)->x > md_pnt)
		{
			pa(a, b);
			i++;
		}
		else if ((*b)->x <= md_pnt)
		{
			rb(b);
			n++;
		}
	}
	sort_a(a, b, i);
	i = n;
	while (n != 0)
	{
		pa(a, b);
		n--;
	}
	sort_a(a, b, i);
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
