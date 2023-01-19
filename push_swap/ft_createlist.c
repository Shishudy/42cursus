/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:51:26 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/19 15:56:13 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Returns address of last node
t_list	*ft_lstend(t_list *lst, int x)
{
	if (!lst)
		return (0);
	while (lst->next && lst->content != (void *)(__INTPTR_TYPE__) x)
		lst = lst->next;
	// Check if x is a number already present on list a.k.a duplicates
	if (lst->content == (void *)(__INTPTR_TYPE__) x)
		exit (ft_printf("%s\n", "Error"));
	return (lst);
}
// Creates new node with x and then adds to list
void	ft_addtolist(t_list **lst, int x)
{
	t_list	*temp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = (void *)(__INTPTR_TYPE__)x;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstend(*lst, x);
	temp->next = new;
}
