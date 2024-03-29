/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:51:26 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 18:01:58 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstend(t_list *a, int x)
{
	t_list	*temp;

	if (!a)
		return (0);
	temp = a;
	while (temp->next && temp->x != x)
		temp = temp->next;
	if (temp->x == x)
		deallocate(&a, 1);
	return (temp);
}

void	ft_addtolist(t_list **a, int x)
{
	t_list	*temp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->x = x;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	temp = *a;
	while (temp->next && temp->x != x)
		temp = temp->next;
	if (temp->x == x)
	{
		free (new);
		deallocate(a, 1);
	}
	temp->next = new;
}
