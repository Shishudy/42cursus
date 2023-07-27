# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rasantos <rasantos@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:47:55 by rasantos          #+#    #+#              #
#    Updated: 2023/07/27 17:05:46 by rasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS	= -L ./minilibx-linux/ -lmlx -lXext -lX11
RM		= rm -f
NAME	= so_long
NAME_BONUS	= so_long_bonus
INCLUDE	= -I ./srcs minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a
INCLUDE_BONUS	= -I ./srcs_bonus minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a
SRCS	= srcs/check_movs_utils.c srcs/check_movs.c srcs/close_game.c \
	srcs/error_messages.c srcs/get_next_line_utils.c srcs/get_next_line.c \
	srcs/key_hooks.c srcs/load_player_idle.c srcs/load_player_run.c srcs/main.c \
	srcs/map_check_utils.c srcs/map_check.c srcs/map_creation.c srcs/movements.c \
	srcs/moving_images.c srcs/pixel_put.c srcs/random_func.c srcs/static_images.c \
	srcs/window_creation.c
SRCS_BONUS	= srcs_bonus/check_movs_utils.c srcs_bonus/check_movs.c srcs_bonus/close_game.c \
	srcs_bonus/error_messages.c srcs_bonus/get_next_line_utils.c srcs_bonus/get_next_line.c \
	srcs_bonus/key_hooks.c srcs_bonus/load_enemy.c srcs_bonus/load_player_idle.c \
	srcs_bonus/load_player_run.c srcs_bonus/main.c srcs_bonus/map_check_utils.c \
	srcs_bonus/map_check.c srcs_bonus/map_creation.c srcs_bonus/movements.c \
	srcs_bonus/moving_images.c srcs_bonus/pixel_put.c srcs_bonus/random_func.c \
	srcs_bonus/static_images.c srcs_bonus/window_creation.c
GREEN 		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME):
	@make -C minilibx-linux --no-print-directory
	@make -C ft_printf --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) has been created$(RESET)"

$(NAME_BONUS):
	@make -C minilibx-linux --no-print-directory
	@make -C ft_printf --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS_BONUS) $(INCLUDE_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) has been created$(RESET)"

clean:
	@make clean -C minilibx-linux --no-print-directory
	@make clean -C ft_printf --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ft_printf --no-print-directory
	@echo "$(RED)$(NAME) has been deleted$(RESET)"
	@$(RM) $(NAME_BONUS)
	@echo "$(RED)$(NAME_BONUS) has been deleted$(RESET)"
re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader ./srcs ./srcs_bonus
	@norminette -R CheckDefine ./srcs ./srcs_bonus

.PHONY: clean, fclean, all, re
