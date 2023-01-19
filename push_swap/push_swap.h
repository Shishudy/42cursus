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

int 	check_argv(char **argv, t_list s_stack_a);
t_list	*ft_lstend(t_list *lst, int x);
void	ft_addtolist(t_list **lst, int x);

#endif
