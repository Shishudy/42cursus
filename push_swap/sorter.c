/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:20:37 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/19 19:46:54 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list s_a, t_list s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = &s_a;
	s_stack_b = &s_b;
	if (s_stack_b->content != NULL)
		return (1);
	while (s_stack_a->next)
	{
		if (s_stack_a->content > s_stack_a->next->content)
			return (1);
		s_stack_a = s_stack_a->next;
	}
}

void	sort_to_b(t_list s_a, t_list s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = &s_a;
	s_stack_b = &s_b;
	while(s_stack_a->next)
	{
		if (s_stack_a->content < s_stack_a->next->content && s_stack_b->content < s_stack_b->next->content)
		{
			ss;
			pb;
		}
		else if (s_stack_a->content > s_stack_a->next->content && s_stack_b->content < s_stack_b->next->content)
		{
			sb;
			pb;
		}
		else if (s_stack_a->content < s_stack_a->next->content)
		{
			sa;
			pb;
		}
		else if (s_stack_a->content > s_stack_a->next->content)
			pb;
		s_stack_a = s_stack_a->next;
	}
}

void	sort_to_a(t_list s_a, t_list s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = &s_a;
	s_stack_b = &s_b;
	while(s_stack_b->next)
	{
		if (s_stack_b->content < s_stack_b->next->content && s_stack_a->content < s_stack_a->next->content)
		{
			ss;
			pa;
		}
		else if (s_stack_b->content > s_stack_b->next->content && s_stack_a->content < s_stack_a->next->content)
		{
			sa;
			pa;
		}
		else if (s_stack_b->content < s_stack_b->next->content)
		{
			sb;
			pa;
		}
		else if (s_stack_b->content > s_stack_b->next->content)
			pa;
		s_stack_b = s_stack_b->next;
	}
}