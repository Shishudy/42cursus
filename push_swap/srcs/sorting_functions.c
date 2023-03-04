/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:51:01 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/03 17:52:23 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **t_list_a)
{
	t_list	*second;

	if (!*t_list_a)
		return ;
	second = (*t_list_a)->next;
	(*t_list_a)->next = second->next;
	second->next = *t_list_a;
	*t_list_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **t_list_b)
{
	t_list	*second;

	if (!*t_list_b)
		return ;
	second = (*t_list_b)->next;
	(*t_list_b)->next = second->next;
	second->next = *t_list_b;
	*t_list_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_list **t_list_a, t_list **t_list_b)
{
	sa(t_list_a);
	sb(t_list_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **t_list_a, t_list **t_list_b)
{
	t_list	*curr;

	if (!*t_list_b)
		return ;
	curr = *t_list_b;
	*t_list_b = curr->next;
	curr->next = *t_list_a;
	*t_list_a = curr;
	write(1, "pa\n", 3);
}

void	pb(t_list **t_list_b, t_list **t_list_a)
{
	t_list	*curr;

	if (!*t_list_a)
		return ;
	curr = *t_list_a;
	*t_list_a = curr->next;
	curr->next = *t_list_b;
	*t_list_b = curr;
	write(1, "pb\n", 3);
}

void	ra(t_list **t_list_a)
{
	t_list	*curr;
	t_list	*temp;

	if (!*t_list_a)
		return ;
	curr = *t_list_a;
	temp = *t_list_a;
	*t_list_a = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
    write(1, "ra\n", 3);
}

void	rb(t_list **t_list_b)
{
	t_list	*curr;
	t_list	*temp;

	if (!*t_list_b)
		return ;
	curr = *t_list_b;
	temp = *t_list_b;
	*t_list_b = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_list **t_list_a)
{
	t_list	*curr;
	t_list	*before_last;

	curr = *t_list_a;
	before_last = *t_list_a;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *t_list_a;
	*t_list_a = curr;
	before_last->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **t_list_b)
{
	t_list	*curr;
	t_list	*before_last;

	curr = *t_list_b;
	before_last = *t_list_b;
	while (curr->next != NULL)
		curr = curr->next;
	while (before_last->next != curr)
		before_last = before_last->next;
	curr->next = *t_list_b;
	*t_list_b = curr;
	before_last->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **t_list_a, t_list **t_list_b)
{
	rra(t_list_a);
	rrb(t_list_b);
	write(1, "rrr\n", 4);
}