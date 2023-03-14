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
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				x;
	struct s_list	*next;
}					t_list;

typedef struct s_mid
{
	t_list			*temp;
	t_list			*last;
	int				n;
	int				i;
	int				md_pnt;
	int				bottom;
}					t_mid;

//----------------Create_stack_a---------------//
void		ft_addtolist(t_list **lst, int x);
t_list		*check_argv(char **argv, t_list *a);
int			split_atoi(char **argv, t_list *a);
t_list		*ft_lstend(t_list *lst, int x);

//----------------Create_stack_b---------------//
int			gv_i(t_list **a, int element);
int			midpoint(t_list **a, int i);
int			numero_movi(t_list **a, int end);
void		send_pb(t_list **a, t_list **b, int top, int bottom);
void		best_move(t_list **a, t_list **b, int start, int end);

//----------------Sort_small---------------//
void		sort_3(t_list **a);
void		sort_4(t_list **a, t_list **b);
void		sort_5(t_list **a, t_list **b);
int			ft_pultimo(t_list **a);
int			ft_meio(t_list **a);
int			small_i(t_list **a);
int			big_i(t_list **a);

//----------------Sort_big---------------//
void		sort_biggest(t_list **a, t_list **b);
void		sort_rest_a(t_list **a, t_list **b, int ra_control, int pb_control);
void		sort_a(t_list **a, t_list **b, int n_moviments);

//---------------Sort_a_utils-----------------//
void		back_ra(t_list **a, int n_control);
void		back_pb(t_list **a, t_list **b, int n_control);
int			sort_a_big(t_list **root, int n_moviments);
int			sort_a_small(t_list **root);

//--------------Send_top--------------------//
int			top_big(t_list *b);
int			top_small(t_list *b);
void		part_send_top(t_list **a, t_list **b, t_list *last, int n);
void		send_top_b(t_list **a, t_list **b);

//--------------Send_bot--------------------//
t_list		*find_last(t_list **b);
int			bot_small(t_list *b);
int			bot_big(t_list *b);
void		sort_back_bot(t_list **a, t_list **b, int i, int n);
void		send_bot_b(t_list **a, t_list **b);

//--------------Send_rest--------------------//
void		send_rest(t_list **a, t_list **b);
int			give_big(t_list **b);
int			give_small(t_list **b);

//--------------Send_utils--------------------//
int			n_midpoint(t_list **root, int start, int end);
int			gv_i_mid(t_list **a);
int			give_value_mid(t_list **a);

//---------------Sort_utils-----------------//
int			start(t_list **a);
int			end(t_list **a);
int			i_last(t_list **root, int finish);
int			i_first(t_list **root, int start);
int			md_chunk(t_list **root, int start, int finish);

//---------------Misc_utils-----------------//
int			cnt_rec(t_list *root);
void		sort_list(t_list **root);
int			list_sorted(t_list **root);
t_list		*clone_list(t_list **root);
void		deallocate(t_list **root, int message);

//----------------Moviments---------------//
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **b, t_list **a);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

#endif