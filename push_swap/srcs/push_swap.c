/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:39:42 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/13 17:52:20 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = check_argv(argv, a);
	if (!a)
		return (0);
	else if (cnt_rec(a) == 2)
		sa(&a);
	else if (cnt_rec(a) == 3)
		sort_3(&a);
	else if (cnt_rec(a) == 4)
		sort_4(&a, &b);
	else if (cnt_rec(a) == 5)
		sort_5(&a, &b);
	else
		sort_biggest(&a, &b);
	deallocate(&a, 0);
	return (0);
}
