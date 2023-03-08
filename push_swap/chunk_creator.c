/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:13:26 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/08 11:28:40 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gv_i(t_list **a, int element)
{
	t_list	*temp;
	int		index_a;

	temp = (*a);
	index_a = 0;
	while (temp->next != NULL && element != temp->x)
	{
		index_a++;
		temp = temp->next;
	}
	return (index_a);
}

int	midpoint(t_list **a, int i)
{
	t_list	*temp;
	int		value;

	temp = clone_list(a);
	sort_list(&temp);
	i = i / 2;
	while (i-- != 0 && temp->next != NULL)
		temp = temp->next;
	value = temp->x;
	deallocate(&temp, 0);
	return (value);
}

int	numero_movi(t_list **a, int end)
{
	t_list	*temp;
	int		i;

	temp = clone_list(a);
	sort_list(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	deallocate(&temp, 0);
	return (i);
}

void	send_pb(t_list **a, t_list **b, int top, int bottom)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			ra(a);
		pb(b, a);
	}
	else if (top > bottom)
	{
		while (bottom-- != 0)
			rra(a);
		pb(b, a);
	}
}

void	best_move(t_list **a, t_list **b, int start, int end)
{
	t_list	*temp;
	int		i;
	int		top;
	int		bottom;
	int		flag;
	int		md_pnt;

	i = numero_movi(a, end);
	md_pnt = midpoint(a, i);
	while (*a && i-- != 0)
	{
		flag = 0;
		temp = (*a);
		while (temp->next != NULL)
		{
			if ((temp->x >= start && temp->x <= end) && flag == 0)
			{
				top = temp->x;
				flag = 1;
			}
			if (temp->x >= start && temp->x <= end)
				bottom = temp->x;
			temp = temp->next;
		}
		send_pb(a, b, gv_i(a, top), (cnt_rec(*a) - gv_i(a, bottom)));
		if (cnt_rec(*b) > 1 && (*b)->x < md_pnt)
			rb(b);
	}
}
