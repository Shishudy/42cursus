# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:26:18 by rasantos          #+#    #+#              #
#    Updated: 2022/12/16 17:26:22 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME        = libftprintf.a
CC      	= gcc
RM      	= rm -f
CFLAGS      = -Wall -Werror -Wextra

#Sources

SRC_FILES   = ft_printf.c ft_putchar.c ft_puthex.c ft_puthex2.c ft_putnbr.c ft_putudec.c ft_putstr.c

#Binaries

OBJS        = $(SRC_FILES:.c=.o)

#Rules

%.o:        %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:        $(NAME)

$(NAME):    $(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:     clean
			$(RM) $(NAME)

re:     fclean all

.PHONY:     all clean fclean re