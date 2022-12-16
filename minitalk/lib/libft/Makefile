# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 17:24:41 by rasantos          #+#    #+#              #
#    Updated: 2022/12/16 17:24:42 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f
NAME	= libft.a
SRCS	= ft_strlen.c ft_memcpy.c ft_atoi.c
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

