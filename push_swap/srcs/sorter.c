/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:20:37 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/25 18:17:01 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_list **s_a, t_list **s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = *s_a;
	s_stack_b = *s_b;
	if (s_stack_b->content == NULL)
		return (1);
	while (s_stack_a->next)
	{
		if (s_stack_a->content > s_stack_a->next->content)
			return (1);
		s_stack_a = s_stack_a->next;
	}
	return (0);
}

void	sort_to_b(t_list **s_a, t_list **s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = *s_a;
	s_stack_b = *s_b;
	while(s_stack_a->next)
	{
		if (s_stack_a->content < s_stack_a->next->content && s_stack_b->content < s_stack_b->next->content)
		{
			ss(s_a, s_b);
			pb(s_a, s_b);
		}
		else if (s_stack_a->content > s_stack_a->next->content && s_stack_b->content < s_stack_b->next->content)
		{
			sb(s_b);
			pb(s_a, s_b);
		}
		else if (s_stack_a->content < s_stack_a->next->content)
		{
			sa(s_a);
			pb(s_a, s_b);
		}
		else if (s_stack_a->content > s_stack_a->next->content)
			pb(s_a, s_b);
		s_stack_a = s_stack_a->next;
	}
}

void	sort_to_a(t_list **s_a, t_list **s_b)
{
	t_list *s_stack_a;
	t_list *s_stack_b;

	s_stack_a = *s_a;
	s_stack_b = *s_b;
	while(s_stack_b->next)
	{
		if (s_stack_b->content < s_stack_b->next->content && s_stack_a->content < s_stack_a->next->content)
		{
			ss(s_a, s_b);
			pa(s_b, s_a);
		}
		else if (s_stack_b->content > s_stack_b->next->content && s_stack_a->content < s_stack_a->next->content)
		{
			sa(s_a);
			pa(s_b, s_a);
		}
		else if (s_stack_b->content < s_stack_b->next->content)
		{
			sb(s_b);
			pa(s_b, s_a);
		}
		else if (s_stack_b->content > s_stack_b->next->content)
			pa(s_b, s_a);
		s_stack_b = s_stack_b->next;
	}
}