/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:40:39 by csouita           #+#    #+#             */
/*   Updated: 2025/03/28 00:09:45 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_file(char *line, t_map *data)
{
	if ((!line && data->info->height == 0) || count_len(data) == 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		free_elements(data);
		free_2d(data->kharita);
		free(data->info);
		free(data);
		exit(1);
	}
}

int	validate_texture_format(char **split, t_map *data)
{
	if (count_split(split) != 2)
	{
		ft_putstr_fd("Error\nInvalid texture\n", 2);
		free_2d(split);
		free_elements(data);
		free_2d(data->kharita);
		free(data->info);
		free(data);
		return (-1);
	}
	return (0);
}

int	process_texture_line(t_map *data, char **split)
{
	if (validate_texture_format(split, data) == -1)
		return (-1);
	if (!strcmp(split[0], "NO"))
		return (set_no_texture(data, split));
	else if (!strcmp(split[0], "SO"))
		return (set_so_texture(data, split));
	else if (!strcmp(split[0], "WE"))
		return (set_we_texture(data, split));
	else if (!strcmp(split[0], "EA"))
		return (set_ea_texture(data, split));
	else if (!strcmp(split[0], "F"))
		return (set_floor_and_ceiling_color(data, split, 1));
	else if (!strcmp(split[0], "C"))
		return (set_floor_and_ceiling_color(data, split, 0));
	return (0);
}

void	process_texture_data(t_map *data, char *line, int *j)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split00(line);
	if (!check_empty(line))
	{
		free_2d(split);
		free(line);
		data->info->first_line_in_map++;
		return ;
	}
	if (process_texture_line(data, split) == -1)
	{
		free(line);
		exit(1);
	}
	free_2d(split);
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
	free(line);
	close(fd);
	return (1);
}
