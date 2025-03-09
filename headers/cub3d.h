/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:35:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/08 00:36:49 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <mlx.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data
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
}   t_data;


void ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(char *s1);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int    ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
long	ft_atoi(char *str);
int	create_trgb(int t, int r, int g, int b);
char	**ft_split00(char *s);
int	parse_textures(t_data *data);
int	check_xpm(t_data *data);
int	set_no_texture(t_data *data, char **split);
int	set_so_texture(t_data *data, char **split);
int	set_we_texture(t_data *data, char **split);
int	set_ea_texture(t_data *data, char **split);
int	set_floor_and_ceiling_color(t_data *data, char **split , int i);
int	    handle_colors(char *line);
int	    count_split(char **split);
void	ft_error(char *str);
void	process_texture_data(t_data *data, char *line, int *j);
void	process_texture_line(t_data *data, char **split);
void	check_invalid_character(t_data *data);
void	check_boundaries(t_data *data);
int	check_empty(char *line);
int	parse_element(t_data *data, int *i);
int	count_len(t_data *data);
int	check_player_valid_pos(t_data *data);
int	handle_colors(char *line);
void	ft_check_file_path(t_data *data, int ac, char *av[]);
void	map_height(t_data *data, char *av[]);
void	cp_map_array(t_data *data, char *av[]);
int	    last_line(t_data *data);
void	first_line_in_map(t_data *data);
int	    first_and_last_lines_check(t_data *data);
char	**freefun00(char **p, int j);
int	handle_quotes3(char *str, int *i, char quote_char);
int	ft_is_void(char c);
int	free_memory(t_data *data);
void	validate_texture_format(char **split , t_data *data);
void free_elements(t_data *data);


#endif