# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:47:55 by rasantos          #+#    #+#              #
#    Updated: 2023/05/23 17:46:13 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
MLX_FLAGS	= -L ./minilibx-linux/ -lmlx -lXext -lX11
RM		= rm -f
NAME	= so_long
INCLUDE	= srcs/so_long.h srcs/get_next_line.h minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a
SRCS	= ${wildcard srcs/*.c}
OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	@make -C ft_printf --no-print-directory
	@make -C minilibx-linux --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(MLX_FLAGS)

clean: 
	@$(RM) $(OBJS) ${wildcard srcs/*.h.gch}
	@make clean -C minilibx-linux --no-print-directory
	@make clean -C ft_printf --no-print-directory
fclean: clean
	@$(RM) $(NAME)
	@make clean -C minilibx-linux --no-print-directory
	@make fclean -C ft_printf --no-print-directory
re: fclean all

.PHONY: clean, fclean, all, re