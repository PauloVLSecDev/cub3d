# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 01:01:06 by yurivieirad       #+#    #+#              #
#    Updated: 2025/10/16 19:02:39 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src
SRC_DIR_BONUS = src_bonus
OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
INCLUDES = inc

ENABLE_MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

FILES =	$(SRC_DIR)/floodfill.c \
		$(SRC_DIR)/func_list.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/map_utils.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/move_player.c \
		$(SRC_DIR)/parse_textures.c \
		$(SRC_DIR)/render_utils.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/utils_render.c \
		$(SRC_DIR)/utils_tex.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/parse_main.c 

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(FILES))

MANDATORY_NAMES = $(notdir $(FILES))

FILES_BONUS_NAMES = $(MANDATORY_NAMES) minimap.c

SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS_NAMES))

OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c,$(OBJ_DIR_BONUS)/%.o,$(SRCS_BONUS))

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(ENABLE_MLX) -o $(NAME)

bonus: $(OBJ_DIR_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft $(ENABLE_MLX) -o $(NAME)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(INCLUDES)/cub3d_bonus.h $(INCLUDES)/keycaps.h | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX_LIB)
