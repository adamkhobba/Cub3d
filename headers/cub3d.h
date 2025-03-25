/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:35:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/25 20:18:29 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CUB_SIZE 64
# define WALL_STRIP_W 1
# define FOV 60
# define MINI_MAP 0.2
# define WIDTH 1500
# define HEIGHT 800
# define NAME "\e[1;34mCub3D\e[0m"
# define ERROR "\e[1;31mError\e[0m"

typedef enum s_keys
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	LEFT_ARROW = XK_Left,
	RIGHT_ARROW = XK_Right,
	EXIT = 65307
}					t_keys;

/**
 * @struct s_point
 * @brief A structure to represent a point in 2D space.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 */
typedef struct s_point
{
	double			x;
	double			y;
}					t_point;



/**
 * struct s_player - Structure to represent a player in the game.
 * @param x: The x-coordinate of the player's pos.
 * @param y: The y-coordinate of the player's pos.
 * @param radius: The radius of the player.
 * @param turn_direction: The direction the player is turning (-1 for left,
	+1 for right).
 * @param walk_direction: The direction the player is walking (-1 for back,
	+1 for front).
 * @param rot_angle: The current rotation angle of the player.
 * @param walk_speed: The speed at which the player walks.
 * @param turn_speed: The speed at which the player turns.
 */
typedef struct s_player
{
	t_point			pos;
	int				radius;
	int				turn_direction;
	int				walk_direction;
	double			rot_angle;
	double			walk_speed;
	double			turn_speed;
}					t_player;

typedef struct s_ray
{
	double			angle;
	t_point			wall_hit;
	double			distance;
	bool			was_hit_vertical;
	int				is_ray_facing_down;
	int				is_ray_facing_up;
	int				is_ray_facing_right;
	int				is_ray_facing_left;
	int				wall_hit_content;
}					t_ray;

/**
 * @struct s_map

* @brief 	Structure to store the map data and related information for the game.
 *
 * This structure holds various attributes related to the map,
	including its dimensions,
 * file path, texture paths, color information,
	and player position. It is used to manage
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
 * @param player_x 	Player's x pos on the map.
 * @param player_y 	Player's y pos on the map.
 * @param first_line_in_map 	Index of the first line in the map array.
 * @param last_line_in_map 	Index of the last line in the map array.
 */

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}
					t_img;
typedef struct s_info
{
	int				height;
	int				width;
	char			*file;
	char			*c;
	char			*f;
	char			*no_key;
	char			*so_key;
	char			*we_key;
	char			*ea_key;
	char			*c_key;
	char			*f_key;
	int				first_line_in_map;
	int				last_line_in_map;
	int				boudaries_width;
	int				player_in_x;
	int				player_in_y;
}					t_info;

typedef struct s_map
{
	t_info			*info;
	int				map_width;
	int				map_height;
	char			**kharita;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				color_f;
	int				color_c;
	int				player_x;
	int				player_y;
}					t_map;


typedef struct s_mlx
{
	void			*instance;
	void			*win;
	struct s_img	image;
	int				win_width;
	int				win_height;
}					t_mlx;

typedef struct s_data
{
	t_mlx			mlx;
	t_list			*garbage;
	t_map			*map;
	t_player		*player;
	t_img 			*textures[4];
}					t_data;

// @addindex main.c
t_data				*get_data(void);

// @addindex parsing/check_boundaries_utils.c
void				cp_flkharita(t_map *data);

// @addindex parsing/check_boundaries.c
void				check_boundaries(t_map *data);
void				player_possitions(t_map *data);

// @addindex parsing/check_cell_boundaries.c
void				check_cell_boundaries(t_map *data, int i, int j);
int					check_empty(char *line);

//@addindex parsing/check_character.c
void				check_invalid_character(t_map *data);
int					parse_element(t_map *data, int *i);

// @addindex parsing/check_color.c
int					handle_colors(char *line, t_map *data);
void				free_elements(t_map *data);
int					create_trgb(int t, int r, int g, int b);

// @addindex parsing/check_lines.c
int					first_and_last_lines_check(t_map *data);
void				first_line_in_map(t_map *data);
int					count_len(t_map *data);
int					last_line(t_map *data);

// @addindex parsing/check_player.c
int					check_player_valid_pos(t_map *data);

//@addindex parsing/check_textures_2.c
int					set_floor_and_ceiling_color(t_map *data, char **split,
						int i);
int					set_no_texture(t_map *data, char **split);
int					set_ea_texture(t_map *data, char **split);
int					set_we_texture(t_map *data, char **split);
int					set_so_texture(t_map *data, char **split);

// @addindex parsing/check_textures.c
int					parse_textures(t_map *data);
void				process_texture_data(t_map *data, char *line, int *j);
void				process_texture_line(t_map *data, char **split);
void				validate_texture_format(char **split, t_map *data);

// @addindex parsing/check_valid_texture.c
void				check_valid_texture(t_map *data);

// @addindex parsing/check.c
void				ft_check_file_path(t_map *data, int ac, char *av[]);
int					check_xpm(t_map *data);

// @addindex parsing/count.c
void				map_height(t_map *data, char *av[]);
int					count_split(char **split);

// @addindex parsing/cub3d.c
t_map				*parsing(int ac, char *av[]);
void				free_memory(t_map *data);
void				cp_map_array(t_map *data, char *av[]);
void				ft_error(char *str, t_map *data);

// @addindex parsing/ft_atoi00.c
long				ft_atoi00(char *str);

// @addindex parsing/ft_split_utils.c
char				**freefun00(char **p, int j);
int					handle_quotes3(char *str, int *i, char quote_char);
int					ft_is_void(char c);

// @addindex parsing/ft_split00.c
char				**ft_split00(char *s);

//@addindex parsing/get_next_line.c
char				*get_next_line(int fd);

// @addindex utilities/exit.c
int					close_program(void);

// @addindex utilities/mlx_utils.c
void				my_put_pixel_to_image(int x, int y, int color);

// @addindex game_element/_2dmap.c
void				fillrect(t_point point, int width, int height, int color);
void				_2dmap(t_map *map);
void				_2dmap_render(t_data *data);
void				fillline(t_point from, t_point to, double angle, int color);

// @addindex game_element/player.c
void				player_init(t_data *data);
void				put_player(t_player *player);
int					update_player(int keycode, t_data *data);
int					update_player_release(int keycode);

// @addindex utilities/math.c
double				radtodeg(double rad);
double				degtorad(double deg);
double				cal_distance(t_point point1, t_point point2);

// @addindex utilities/print_fts.c
void				map_print(t_map *data);

// @addindex game_element/check_fts.c
bool				is_wall(int x, int y);

// @addindex utilities/no_need.c
t_map				*fake_map_init(void);
void				free_map(t_map *map);

// @addindex raycasting/raycasting.c
t_ray				*raycasting(t_data *data, int num_rays);

// @addindex raycasting/ray_functions.c
t_ray				ray_create(double angle);
double				normalize_angle(double angle);
void				ray_render(t_ray *ray, t_data *data);
void				ray_render_many(t_ray *rays, int num_rays);

// @addindex raycasting/projection_wall.c
void				render_projection_walls(t_ray *rays, int num_rays);
void 				init_text(t_data *data);

// @addindex raycasting/intersection.c
t_point				horz_intersection(t_data *data, t_ray *ray);
t_point				vert_intersection(t_data *data, t_ray *ray);

// @addindex raycasting/texture.c
unsigned int		get_pixel_img(t_img *data, int x, int y);
t_img				*initialize_text(t_data *data, char *path);
void				init_text(t_data *data);

#endif