# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 01:30:15 by akhobba           #+#    #+#              #
#    Updated: 2025/03/09 23:47:04 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFLAGS
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address
MLXFLAGS	=	-lmlx -lX11 -lXext -lm
HEADERS		=	headers/cub3d.h
INCLUDES	=	-I./headers -I./libft/headers
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
SRC			=	src/parsing/check_boundaries.c src/parsing/check_color.c src/parsing/check_textures_2.c \
				src/parsing/cub3d.c src/parsing/check.c src/parsing/check_lines.c src/parsing/check_textures.c \
				src/parsing/get_next_line.c src/parsing/check_character.c   src/parsing/check_player.c\
				src/parsing/count.c src/parsing/get_next_line_utils.c
SRC			=	src/parsing/check_boundaries.c src/parsing/check_color.c src/parsing/check_textures_2.c \
				src/parsing/cub3d.c src/parsing/check.c src/parsing/check_lines.c src/parsing/check_textures.c \
				src/parsing/get_next_line.c src/parsing/check_character.c   src/parsing/check_player.c\
				src/parsing/count.c src/parsing/get_next_line_utils.c

OBJDIR		=	obj
OBJ			=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,$(SRC))

# Libft
LIBFT		=	libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "\e[K$(GREEN)$(NAME) is ready to use.$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo -n "$(YELLOW)Compiling $(CYAN)$<$(NC)\e[K\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || (echo "$(RED)Error: $(CYAN)$<$(NC)$(RED) is not compiled.$(NC)" && exit 1)

clean:
	@rm -rf $(OBJDIR)
	@echo -n "$(YELLOW)Do you want to clean $(LIBFTPATH)/obj?$(END) [$(RED)y$(END)/$(GREEN)N$(END)] " && read REPLY; \
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(LIBFTPATH)/obj...$(END)"; \
		echo; \
		make -C $(LIBFTPATH) fclean > /dev/null; \
	fi
	@echo "$(RED)Objects are removed.$(END)"

fclean: clean
	@rm -f $(NAME)
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(LIBFTPATH)/obj...$(END)"; \
		echo; \
		make -C $(LIBFTPATH) fclean > /dev/null; \
	fi
	@echo "$(RED)$(NAME) is removed.$(END)"

re: fclean all

# PHONY
.PHONY: all clean fclean re