/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:35:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/09 23:39:46 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 600
# define NAME "\e[1;34mCub3D\e[0m"
# define ERROR "\e[1;31mError\e[0m"

/**
 * @struct s_map
 * @brief 	Structure to store the map data and related information for the game.
 *
 * This structure holds various attributes related to the map, including its dimensions,
 * file path, texture paths, color information, and player position. It is used to manage
 * and access the map data efficiently throughout the game.
 *
 * @param height 	Height of the map in terms of number of rows.
 * @param width 	Width of the map in terms of number of columns.
 * @param file 	File path of the map file.
 * @param map 	2D array representing the map layout.
 * @param no 		Path to the North texture.
 * @param so 		Path to the South texture.
 * @param we 		Path to the West texture.
 * @param ea 		Path to the East texture.
 * @param c 		Ceiling color in string format.
 * @param f 		Floor color in string format.
 * @param no_key 	Key identifier for the North texture.
 * @param so_key 	Key identifier for the South texture.
 * @param we_key 	Key identifier for the West texture.
 * @param ea_key 	Key identifier for the East texture.
 * @param c_key 	Key identifier for the Ceiling color.
 * @param f_key 	Key identifier for the Floor color.
 * @param color_f 	Floor color in integer format.
 * @param color_c 	Ceiling color in integer format.
 * @param player_x 	Player's x position on the map.
 * @param player_y 	Player's y position on the map.
 * @param first_line_in_map 	Index of the first line in the map array.
 * @param last_line_in_map 	Index of the last line in the map array.
 */
typedef struct s_map
{
    int height;
    int width ;
    char *file;
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *c;
    char *f;
    char *no_key;
    char *so_key;
    char *we_key;
    char *ea_key;
    char *c_key;
    char *f_key;
    int color_f;
    int color_c;
    int player_x;
    int player_y;
    int first_line_in_map;
    int last_line_in_map;
}   t_map;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_mlx
{
	void				*instance;
	void				*win;
	struct s_img		image;
}						t_mlx;

typedef struct s_data
{
	t_mlx				mlx;
	t_list				*garbage;
}						t_data;

// Global variable
t_map	*get_data(void);

// @addindex
int	create_trgb(int t, int r, int g, int b);
char	**ft_split00(char *s);
int	parse_textures(t_map *data);
int	check_xpm(t_map *data);
int	set_no_texture(t_map *data, char **split);
int	set_so_texture(t_map *data, char **split);
int	set_we_texture(t_map *data, char **split);
int	set_ea_texture(t_map *data, char **split);
int	set_floor_and_ceiling_color(t_map *data, char **split , int i);
int	    handle_colors(char *line);
int	    count_split(char **split);
void	ft_error(char *str);
void	process_texture_data(t_map *data, char *line, int *j);
void	process_texture_line(t_map *data, char **split);
void	check_invalid_character(t_map *data);
void	check_boundaries(t_map *data);
int	check_empty(char *line);
int	parse_element(t_map *data, int *i);
int	count_len(t_map *data);
int	check_player_valid_pos(t_map *data);
int	handle_colors(char *line);
void	ft_check_file_path(t_map *data, int ac, char *av[]);
void	map_height(t_map *data, char *av[]);
void	cp_map_array(t_map *data, char *av[]);
int	    last_line(t_map *data);
void	first_line_in_map(t_map *data);
int	    first_and_last_lines_check(t_map *data);
char	**freefun00(char **p, int j);
int	handle_quotes3(char *str, int *i, char quote_char);
int	ft_is_void(char c);
int	free_memory(t_map *data);
void	validate_texture_format(char **split , t_map *data);
void free_elements(t_map *data);


#endif