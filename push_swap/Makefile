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
RM		= /bin/rm -f
NAME	= push_swap
INCLUDE	= sources/push_swap.h
SRCS	= sources/push_swap.c\
		  sources/push_swap_printer.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	@make -C ./libft --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) ./sources/push_swap.h ./libft/libft.a

clean: 
	@$(RM) $(OBJS)
	@make clean -C ./libft --no-print-directory
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft --no-print-directory
re: fclean all

.PHONY: clean, fclean, all, re