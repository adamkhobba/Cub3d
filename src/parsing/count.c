/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:04:43 by csouita           #+#    #+#             */
/*   Updated: 2025/03/25 21:41:25 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_textures(t_map *data)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(data->info->file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
			|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		{
			count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	map_height(t_map *data, char *av[])
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->info->height = i;
}
