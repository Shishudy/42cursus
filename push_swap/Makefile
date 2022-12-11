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
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= push_swap

INCLUDE	= sources/push_swap.h
SRCS	= sources/push_swap.c\
		  sources/push_swap_printer.c\
		  

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)