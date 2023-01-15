/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:51:26 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/15 19:21:55 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Returns address of last node
t_list	*ft_lstlast(t_list *lst, int x)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		// Check if x is a number already present on list a.k.a duplicates
		if (lst->x == x)
			exit ("Error");
		lst = lst->next;
	}
	return (lst);
}
// Creates new node with x and then adds to list
void	ft_lstadd_back(t_list **lst, int x)
{
	t_list	*temp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst, x);
	temp->next = new;
}
