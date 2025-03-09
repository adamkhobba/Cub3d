# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouita <csouita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 01:30:15 by akhobba           #+#    #+#              #
#    Updated: 2025/03/09 23:40:36 by csouita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFLAGS
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address
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
SRC			=	src/*.c  src/*/*.c

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