/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:27:38 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 18:10:03 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deallocate(t_list **root, int message)
{
	t_list	*temp;

	while (*root)
	{
		temp = (*root)->next;
		free(*root);
		*root = temp;
	}
	if (message == 2)
		exit(0);
	if (message == 1)
		exit (write(1, "Error\n", 6));
}

int	cnt_rec(t_list *root)
{
	if (root == NULL)
		return (0);
	return (1 + cnt_rec(root->next));
}

int	list_sorted(t_list **root)
{
	t_list	*curr;

	if (!root)
		return (0);
	curr = *root;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sort_list(t_list **root)
{
	t_list	*current;
	t_list	*index;
	int		temp;

	if (!*root)
		return ;
	temp = 0;
	index = NULL;
	current = *root;
	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->x > index->x)
			{
				temp = current->x;
				current->x = index->x;
				index->x = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

t_list	*clone_list(t_list **root)
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	new_list = NULL;
	curr = *root;
	while (curr != NULL)
	{
		new_node = malloc(sizeof(t_list));
		new_node->x = curr->x;
		new_node->next = NULL;
		if (prev != NULL)
			prev->next = new_node;
		else
			new_list = new_node;
		prev = new_node;
		curr = curr->next;
	}
	return (new_list);
}
