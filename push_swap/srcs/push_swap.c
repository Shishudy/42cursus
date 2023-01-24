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

int main(int argc, char **argv)
{
	t_list *s_a;
	//t_list *s_b;

	(void)argc;
	s_a = check_argv(argv, s_a);
	/*while (check_sort(*s_a, *s_b) == 1)
	{
		sort_to_b(*s_a, *s_b);
		sort_to_a(*s_a, *s_b);
	}*/
	while (s_a != NULL)
	{
		ft_printf("%i\n", s_a->content);
		s_a = s_a->next;
	}
	return (0);
}
