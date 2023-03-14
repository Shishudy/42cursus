/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:09:05 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 18:09:06 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a_big(t_list **root, int n_moviments)
{
	t_list	*temp;
	int		biggest;

	temp = (*root);
	biggest = temp->x;
	while (--n_moviments > 0)
	{
		if (biggest < temp->next->x)
			biggest = temp->next->x;
		temp = temp->next;
	}
	return (biggest);
}

int	sort_a_small(t_list **root)
{
	t_list	*temp;
	int		smallest;

	temp = *root;
	smallest = 0;
	while (temp->next != NULL)
	{
		if (temp->x > temp->next->x)
			smallest = temp->next->x;
		temp = temp->next;
	}
	return (smallest);
}
