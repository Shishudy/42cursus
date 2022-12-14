# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:07:05 by israelorien       #+#    #+#              #
#    Updated: 2022/12/14 16:52:03 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f
NAME	= libft.a
SRCS	= ft_strlen.c
OBJS	= $(SRCS:.c=.o)

# Commands
all: $(NAME)
$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean:		clean
	$(RM) $(NAME)
re:	fclean all

.PHONY:	all clean fclean re

