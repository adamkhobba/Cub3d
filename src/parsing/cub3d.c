/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 20:15:48 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_map *data)
{
	ft_putstr_fd(str, 2);
	free_elements(data);
	free_memory(data);
	exit(1);
}

char	**init_split_memory(t_map *data)
{
	char	**split;

	split = malloc(sizeof(char *) * (data->info->height + 1));
	if (!split)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free_memory(data);
		exit(1);;
	}
	return (split);
}

void	cp_map_array(t_map *data, char *av[])
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	data->kharita = malloc(sizeof(char *) * (data->info->height + 1));
	if (!data->kharita)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free_memory(data);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->kharita[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->kharita[i] = NULL;
	close(fd);
}

void	free_memory(t_map *map)
{
	int	i;

	i = 0;
	if (map->info)
		free(map->info);
	if (map->kharita)
	{
		while (map->kharita[i])
		{
			free(map->kharita[i]);
			i++;
		}
		free(map->kharita);
	}
	free(map);
}
t_map	*parsing(int ac, char *av[])
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	ft_memset(data, 0, sizeof(t_map));
	data->info = malloc(sizeof(t_info));
	if (!data->info)
	{
		ft_putstr_fd("Error\nMemory allocation failed for info struct\n", 2);
		free(data);
		exit(1);
	}
	ft_memset(data->info, 0, sizeof(t_info));
	ft_check_file_path(data, ac, av);
	map_height(data, av);
	cp_map_array(data, av);
	check_invalid_character(data);
	check_boundaries(data);
	last_line(data);
	parse_textures(data);
	if (first_and_last_lines_check(data))
		exit(1);
	if (check_xpm(data))
	{
		free_elements(data);
		free_memory(data);
	}
	first_line_in_map(data);
	check_player_valid_pos(data);
	cp_flkharita(data);
	player_possitions(data);
	printf("last line in map %d\n", data->info->last_line_in_map);
	printf("first line in map %d\n", data->info->first_line_in_map);
	printf("map height %d\n", data->map_height);
	printf("map width %d\n", data->map_width);
	fill_map_array(data);
	return (data);
}
