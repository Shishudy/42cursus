/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:04:15 by rasantos          #+#    #+#             */
/*   Updated: 2022/12/03 17:04:15 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstlen(t_list *s_a)
{
	int	len;

	if (!s_a)
		return (0);
	len = 0;
	while (s_a->next != 0)
	{
		s_a = s_a->next;
		len++;
	}
	return (len);
}

int main(int argc, char **argv)
{
	t_list *s_a;
	int	len;

	if (argc <= 1)
		return (0);
	s_a = NULL;
	s_a = check_argv(argv, s_a);
	len = ft_lstlen(s_a);
	if (len <= 3)
		small_sort(&s_a);
	else
		big_sort(len, &s_a);
	while (s_a != NULL)
	{
		ft_printf("%i\n", s_a->content);
		s_a = s_a->next;
	}
	return (0);
}
