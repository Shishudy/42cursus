# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 17:11:02 by rasantos          #+#    #+#              #
#    Updated: 2022/12/03 17:11:02 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= push_swap
INCLUDE	= srcs/push_swap.h
SRCS	= ${wildcard srcs/*.c}
OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	@make -C ft_printf --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) srcs/push_swap.h ft_printf/libftprintf.a

clean: 
	@$(RM) $(OBJS)
	@make clean -C ft_printf --no-print-directory
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ft_printf --no-print-directory
re: fclean all

.PHONY: clean, fclean, all, re