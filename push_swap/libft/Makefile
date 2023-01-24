# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 10:04:47 by rasantos          #+#    #+#              #
#    Updated: 2023/01/23 19:55:33 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB		= ar -rcs
RL		= ranlib
RM		= /bin/rm -f

NAME	= libft.a

INCLUDE	= includes
SRCS	= ${wildcard srcs/*.c}
OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)


$(NAME):	$(OBJS)
			@$(LIB) $(NAME) $(OBJS)
			@$(RL) $(NAME)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
