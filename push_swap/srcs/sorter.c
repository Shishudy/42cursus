/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:20:37 by rasantos          #+#    #+#             */
/*   Updated: 2023/02/13 15:43:18 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **s_a)
{
	t_list	*s_stack_a;
	t_list	*temp;

	s_stack_a = *s_a;
	temp = ft_lstnew(s_stack_a->content);
	s_stack_a->content = s_stack_a->next->content;
	s_stack_a->next->content = temp->content;
	ft_printf("%s\n", "sa");
}

void	ra(t_list **s_a)
{
	t_list	*s_stack_a;

	s_stack_a = *s_a;
	ft_lstadd_back(&s_stack_a, s_stack_a->content);
	ft_printf("%s\n", "ra");
}

//3 2 1 / 2 3 1 / 3 1 2 / 1 3 2
void	small_sort(t_list **s_a)
{
	t_list	*a;

	a = s_a;
	if (a->content > a->next->content)
	{
		sa(*s_a);
		ra(*s_a);
	}
	if (a->content > a->next->content)
	{
		ra(*s_a);
	}
}

/*void	big_sort(int len, t_list **s_a)
{
	while (len > 3)
	{
		
		len--;
	}
}*/