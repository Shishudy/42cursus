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

int	start(t_list **a)
{
	t_list	*temp;
	t_list	*clone;
	int		start;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	start = temp->x;
	deallocate(&clone, 0);
	return (start);
}

int	end(t_list **a)
{
	t_list	*temp;
	t_list	*clone;
	int		end;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	end = 0;
	while (temp->next != NULL && end != 29)
	{
		end++;
		temp = temp->next;
	}
	end = temp->x;
	deallocate(&clone, 0);
	return (end);
}

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
	t_list	*clone;
	t_list	*temp;
	int		mid;
	int		result;

	if (start == finish)
		return (start);
	clone = clone_list(root);
	temp = clone;
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
	deallocate(&clone, 0);
	return (result);
}
