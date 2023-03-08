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

//----------------Create_stack_a---------------//
void	ft_addtolist(t_list **lst, int x);
t_list 	*check_argv(char **argv, t_list *a);
t_list	*ft_lstend(t_list *lst, int x);

//----------------Create_stack_b---------------//
int			gv_i(t_list **a, int element);
int			midpoint(t_list **a, int i);
int			numero_movi(t_list **a, int end);
void		send_pb(t_list **a, t_list **b, int top, int bottom);
int			start(t_list **a);
int			end(t_list **a);
void		best_move(t_list **a, t_list **b, int start, int end);

//----------------Moviments---------------//
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **b, t_list **a);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a ,t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

//--------------Send_top--------------------//
int         top_big(t_list *b);
int		    top_small(t_list *b);
void        sort_back_top(t_list **a, t_list **b, int i, int n);
void		send_top_b(t_list **a, t_list **b);

//--------------Send_bot--------------------//
t_list	*find_last(t_list **b);
int		bot_small(t_list *b);
int		bot_big(t_list *b);
void	sort_back_bot(t_list **a, t_list **b, int i, int n);
void	send_bot_b(t_list **a, t_list **b);

//--------------Send_rest--------------------//
void		send_rest(t_list **a, t_list **b);

//--------------Send_utils--------------------//
int         n_midpoint(t_list **root, int midpoint, int end);
void		sort_list(t_list **a);
int			small_i(t_list **a);
int			big_i(t_list **a);
int			gv_i_mid(t_list **a);
int			give_value_mid(t_list **a);

//----------------Sort---------------//
void	    sort_3(t_list **a);
void	    sort_5(t_list **a, t_list **b);
void	    sort_biggest(t_list **a, t_list **b);
void	    sort_a(t_list **a, t_list **b, int n_moviments);

//---------------Sort_a_utils-----------------//
void	back_ra(t_list **a, int n_control);
void	back_pb(t_list **a, t_list **b, int n_control);
int	    sort_a_big(t_list **root, int n_moviments);
int	    sort_a_small(t_list **root);
//---------------Sort_utils-----------------//
int	ft_pultimo(t_list **a);
int	ft_meio(t_list **a);
int	i_last(t_list **root, int finish);
int	i_first(t_list **root, int start);
int	md_chunk(t_list **root, int start, int finish);











size_t		ft_strlen(const char *a);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
void		insert_end(t_list **root, int value);
t_list		*initialize_list_link(char **argv, t_list *a);
int			ft_intermedia(char *argv, int delimiter);
int			gv_i_b_a(t_list **a, t_list **b, int position);


//-------------------testing--------------------//

int			midpoint(t_list **a, int i);
void		best_move(t_list **a, t_list **b, int start, int end);
int			sort_biggest_chunks_in_b(t_list **root);
int			i_last(t_list **root, int finish);
int			i_first(t_list **root, int start);
int			md_chunk(t_list **root, int start, int finish);
int			top_small(t_list *b);
int			bot_small(t_list *b);
int			top_big(t_list *b);
int			bot_big(t_list *b);
void		back_ra(t_list **a, int n_control);
void		back_pb(t_list **a, t_list **b, int n_control);
int			find_biggest_chunks_in_a(t_list **root, int n_moviments);
int			find_smallest_chunks_in_a(t_list **root);
void		sort_a(t_list **a, t_list **b, int n_moviments);
void		send_bot_b(t_list **a, t_list **b);
void		send_top_b(t_list **a, t_list **b);
void		send_rest(t_list **a, t_list **b);
void		sort_biggest(t_list **a, t_list **b);

//-----------------------------SORT--------------------------//

int			list_sorted(t_list **root);
void		insert_end(t_list **root, int value);
void		deallocate(t_list **root, int message);
char		write_word(char *dest, const char *from, char set);
char		**ft_split(char const *s, char c);
int			word_count(const char *sr, char delimiter);
void		add_split(char **dst, const char *string, char delimiter);
void		free_all(char **result);
t_list		*initialize_list(char **argv, t_list *a);
void		print_array_2d(char **arr_bidimensional);
int			gv_i_b_a(t_list **a, t_list **b, int position);
t_list		*clone_list(t_list **head);
int			small_i(t_list **a);
int			big_i(t_list **a);
int			ft_pultimo(t_list **a);
int			ft_meio(t_list **a);
int			cnt_rec(t_list *node);
void		send_desire(t_list **a, t_list **b, int meio, int pnultimo);
t_list		*ft_split_create_str(t_list *a, char *argv, char delimiter);
//void		printList(t_list *root);
int			count_items(t_list *root);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isnum_compare(const char *str, t_list *a);
long int	ft_atoi_check_numbers(const char *str, t_list *a);

#endif
