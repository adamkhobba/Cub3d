/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 23:35:45 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_map *data)
{
	ft_putstr_fd(str, 2);
	free_elements(data);
	free_2d(data->kharita);
	free(data->info);
	free(data);
}

char	**init_split_memory(t_map *data)
{
	char	**split;

	split = malloc(sizeof(char *) * (data->info->height + 1));
	if (!split)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free_2d(data->kharita);
		free(data->info);
		free(data);
		exit(1);
	}
	return (split);
}

void	cp_map_array(t_map *data, char *av[])
{
	char	*line;

	int (i), (fd);
	i = 0;
	fd = open(av[1], O_RDONLY);
	data->kharita = malloc(sizeof(char *) * (data->info->height + 1));
	line = get_next_line(fd);
	while (line)
	{
		data->kharita[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->kharita[i] = NULL;
	if (count_len(data) == 0)
	{
		ft_putstr_fd("Error\nInvalid filew\n", 2);
		free_elements(data);
		free_2d(data->kharita);
		free(data->info);
		free(data);
		exit(1);
	}
	close(fd);
}

t_map	*parsing(int ac, char *av[])
{
	t_map	*data;
	int		fd;

	data = malloc(sizeof(t_map));
	ft_memset(data, 0, sizeof(t_map));
	data->info = malloc(sizeof(t_info));
	ft_memset(data->info, 0, sizeof(t_info));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not found\n", 2);
		free(data->info);
		free(data);
		exit(1);
	}
	(ft_check_file_path(data, ac, av), map_height(data, av));
	(cp_map_array(data, av), check_invalid_character(data));
	(check_boundaries(data), last_line(data));
	parse_textures(data);
	if (first_and_last_lines_check(data))
		exit(1);
	(check_xpm(data), first_line_in_map(data));
	(check_player_valid_pos(data), cp_flkharita(data));
	(player_possitions(data), fill_map_array(data));
	return (data);
}
