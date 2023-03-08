/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:07:52 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/07 10:07:52 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	i_last(t_list **root, int finish)
{
	t_list	*temp;
	int		index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == finish)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	i_first(t_list **root, int start)
{
	t_list	*temp;
	int		index;

	temp = *root;
	index = 0;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break ;
		index++;
		temp = temp->next;
	}
	return (index);
}

int	md_chunk(t_list **root, int start, int finish)
{
	t_list	*temp;
	int		mid;
	int		result;

	temp = clone_list(root);
	sort_list(&temp);
	mid = (i_last(&temp, finish) - i_first(&temp, start)) / 2;
	while (temp->next != NULL)
	{
		if (temp->x == start)
			break ;
		temp = temp->next;
	}
	while (mid-- != 0)
		temp = temp->next;
	result = temp->x;
	deallocate(&temp, 0);
	return (result);
}
