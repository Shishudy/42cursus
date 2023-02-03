/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:03 by rasantos          #+#    #+#             */
/*   Updated: 2023/01/15 15:39:03 by rasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

t_list 	*check_argv(char **argv, t_list *s_a);
t_list	*ft_lstend(t_list *lst, int x);
void	ft_addtolist(t_list **lst, int x);
/*int		check_sort(t_list **s_a, t_list **s_b);
void	sort_to_b(t_list **s_a, t_list **s_b);
void	sort_to_a(t_list **s_a, t_list **s_b);
void	sa(t_list **s_a);
void	sb(t_list **s_b);
void	ss(t_list **s_a, t_list **s_b);
void	pa(t_list **s_b, t_list **s_a);
void	pb(t_list **s_a, t_list **s_b);
void	ra(t_list **s_a);
void	rb(t_list **s_b);
void	rr(t_list **s_a, t_list **s_b);
void	rra(t_list **s_a);
void	rrb(t_list **s_b);
void	rrr(t_list **s_a, t_list **s_b);*/

#endif
