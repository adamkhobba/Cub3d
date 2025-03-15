/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:40:39 by csouita           #+#    #+#             */
/*   Updated: 2025/03/15 23:00:31 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_file(char *line, t_map *data)
{
	if ((!line && data->info->height == 0) || count_len(data) == 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		free_elements(data);
		free_memory(data);
	}
}

void	validate_texture_format(char **split, t_map *data)
{
	if (count_split(split) != 2)
	{
		ft_putstr_fd("Error\nInvalid texture\n", 2);
		free_elements(data);
		free_memory(data);
	}
}

void	process_texture_line(t_map *data, char **split)
{
	validate_texture_format(split, data);
	if (!strcmp(split[0], "NO"))
		set_no_texture(data, split);
	else if (!strcmp(split[0], "SO"))
		set_so_texture(data, split);
	else if (!strcmp(split[0], "WE"))
		set_we_texture(data, split);
	else if (!strcmp(split[0], "EA"))
		set_ea_texture(data, split);
	else if (!strcmp(split[0], "F"))
		set_floor_and_ceiling_color(data, split, 1);
	else if (!strcmp(split[0], "C"))
		set_floor_and_ceiling_color(data, split, 0);
}

void	process_texture_data(t_map *data, char *line, int *j)
{
	char	**split;

	split = ft_split00(line);
	if (!check_empty(line))
	{
		free(line);
		data->info->first_line_in_map++;
		return ;
	}
	process_texture_line(data, split);
	free(split);
	free(line);
	(*j)++;
}

int	parse_textures(t_map *data)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(data->info->file, O_RDONLY);
	line = get_next_line(fd);
	check_valid_file(line, data);
	while (line && j < 6)
	{
		process_texture_data(data, line, &j);
		line = get_next_line(fd);
	}
	check_valid_texture(data);
	if (line)
		free(line);
	close(fd);
	return (1);
}
