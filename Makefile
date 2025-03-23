# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 01:30:15 by akhobba           #+#    #+#              #
#    Updated: 2025/03/21 23:56:31 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFLAGS
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 #-fsanitize=address
MLXFLAGS	=	-lmlx -lX11 -lXext -lm
HEADERS		=	headers/cub3d.h
INCLUDES	=	-I./headers -I./libft/headers

# Name
NAME		=	cub3d

# Colors
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;36m
NC			=	\033[0m

# Sources
SRCDIR		=	src
SRC			=	src/main.c src/parsing/check_boundaries.c src/parsing/check_color.c src/parsing/check_textures_2.c \
				src/parsing/cub3d.c src/parsing/check.c src/parsing/check_lines.c src/parsing/check_textures.c \
				src/parsing/get_next_line.c src/parsing/check_character.c   src/parsing/check_player.c\
				src/parsing/count.c src/parsing/ft_split00.c src/parsing/ft_atoi00.c\
				src/utilities/math.c src/utilities/exit.c  src/utilities/mlx_utils.c  \
				src/game_element/player.c src/game_element/_2dmap.c src/game_element/wall_collision.c \
				src/parsing/check_valid_texture.c src/utilities/print_fts.c \
				src/utilities/no_need.c src/raycasting/raycasting.c src/raycasting/projection_wall.c src/raycasting/ray_functions.c \
				src/raycasting/intersection_wall.c src/game_element/hooks.c\
				src/parsing/check_boundaries_utils.c src/parsing/check_cell_boundaries.c \
				src/parsing/ft_split_utils.c

OBJDIR		=	obj
OBJ			=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,$(SRC))

# Libft
LIBFT		=	libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "\e[K$(GREEN)$(NAME) is ready to use.$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	@echo -n "$(YELLOW)Compiling $(CYAN)$<$(NC)\e[K\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || (echo "$(RED)Error: $(CYAN)$<$(NC)$(RED) is not compiled.$(NC)" && exit 1)

clean:
	@rm -rf $(OBJDIR)
	@echo -n "$(YELLOW)Do you want to clean $(LIBFTPATH)/obj?$(NC) [$(RED)y$(NC)/$(GREEN)N$(NC)] " && read REPLY;\
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(LIBFTPATH)/obj...$(NC)"; \
		echo; \
		make -C $(LIBFTPATH) fclean > /dev/null; \
	fi
	@echo "$(RED)Objects are removed.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo -n "$(YELLOW)Do you want to clean $(LIBFT)/obj?$(NC) [$(RED)y$(NC)/$(GREEN)N$(NC)] " && read REPLY; \
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(LIBFT)...$(NC)"; \
		echo; \
		make -C $(LIBFTPATH) fclean > /dev/null; \
	fi
	@echo "$(RED)$(NAME) is removed.$(NC)"
re: fclean all

# PHONY
.PHONY: all clean fclean re