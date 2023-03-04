/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:51:26 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/03 13:57:37 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstend(t_list *a, int x)
{
	t_list	*temp;

	if (!a)
		return (0);
	temp = a;
	while (temp->next && temp->x != (void *)(__INTPTR_TYPE__) x)
		temp = temp->next;
	if (temp->x == (void *)(__INTPTR_TYPE__) x)
		exit (ft_printf("%s\n", "Duplicates"));
	return (temp);
}

void	ft_addtolist(t_list **a, int x)
{
	t_list	*temp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->x = (void *)(__INTPTR_TYPE__)x;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	temp = ft_lstend(*a, x);
	temp->next = new;
}
