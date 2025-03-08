NAME =		cub3d

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror #-g3 -fsanitize=address

SRC = 		cub3d.c ft_putstr_fd.c get_next_line.c get_next_line_utils.c ft_memset.c ft_strcmp.c ft_split.c \
 			ft_strncmp.c ft_strrchr.c ft_atoi.c check_color.c ft_split00.c check_boundaries.c check_character.c \
			check_textures.c check_textures_2.c check_player.c check.c count.c check_lines.c ft_split_utils.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY :