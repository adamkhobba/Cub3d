/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/17 00:40:47 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_map *data)
{
	ft_putstr_fd(str, 2);
	free_elements(data);
	free_memory(data);
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
	check_invalid_character(data);
	close(fd);
}

void	free_memory(t_map *data)
{
	int	k;

	k = 0;
	while (data->kharita[k])
	{
		free(data->kharita[k]);
		k++;
	}
	free(data->info);
	free(data);
	exit(1);
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
	last_line(data);
	parse_textures(data);
	if (check_xpm(data))
	{
		free_elements(data);
		free_memory(data);
	}
	first_line_in_map(data);
	if (first_and_last_lines_check(data))
		free_memory(data);
	check_player_valid_pos(data);
	cp_flkharita(data);
	player_possitions(data);
	free_memory(data);
	return (data);
}
