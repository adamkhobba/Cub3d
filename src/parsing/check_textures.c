/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:40:39 by csouita           #+#    #+#             */
/*   Updated: 2025/03/08 00:35:25 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_file(char *line, t_data *data)
{
	if ((!line && data->height == 0) || count_len(data) == 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		free_elements(data);
		free_memory(data);
	}
}

void	validate_texture_format(char **split, t_data *data)
{
	if (count_split(split) != 2)
	{
		ft_putstr_fd("Error\nInvalid texture\n", 2);
		free_elements(data);
		free_memory(data);
	}
}

void check_free(t_data *data , int flag)
{
	if (flag)
	{
		free_elements(data);
		free_memory(data);
	}
}

void	process_texture_line(t_data *data, char **split)
{
	validate_texture_format(split, data);
	if (!ft_strcmp(split[0], "NO"))
		set_no_texture(data, split);
	else if (!ft_strcmp(split[0], "SO"))
		set_so_texture(data, split);
	else if (!ft_strcmp(split[0], "WE"))
		set_we_texture(data, split);
	else if (!ft_strcmp(split[0], "EA"))
		set_ea_texture(data, split);
	else if (!ft_strcmp(split[0], "F"))
		set_floor_and_ceiling_color(data, split, 1);
	else if (!ft_strcmp(split[0], "C"))
		set_floor_and_ceiling_color(data, split, 0);
}

void	process_texture_data(t_data *data, char *line, int *j)
{
	char	**split;
	int		k;

	k = 0;
	split = ft_split00(line);
	if (!check_empty(line))
	{
		free(line);
		data->first_line_in_map++;
		return ;
	}
	process_texture_line(data, split);
	free(line);
	while (split[k])
	{
		free(split[k]);
		k++;
	}
	free(split);
	(*j)++;
}

int	parse_textures(t_data *data)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(data->file, O_RDONLY);
	line = get_next_line(fd);
	check_valid_file(line, data);
	while (line && j < 6)
	{
		process_texture_data(data, line, &j);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (1);
}
