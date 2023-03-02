/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:39:42 by rasantos          #+#    #+#             */
/*   Updated: 2023/03/01 20:02:13 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    //t_list  *b;

    a = NULL;
    //b = NULL;
    if (argc < 2)
        return (0);
    check_argv(argv, a);
    while (a != NULL)
	{
		if (a->next == NULL)
		{
			ft_printf("[*][%ld]", (long int)a->x);
			break ;
		}
		ft_printf("[*][%ld]->", (long int)a->x);
		a = a->next;
	}
    // if (cnt_recursive(*a) <= 3)
	// 	sort_3(a, b);
	// else if (cnt_recursive(*a) <= 5)
	// 	sort_5(a, b);
	// else
	// 	sort_biggest(a, b);
	// deallocate(&a, 0);
	return (0);
}