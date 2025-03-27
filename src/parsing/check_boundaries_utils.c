/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:39:51 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 01:19:56 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map_array(t_map *data)
{
	char	current;
	char	*line;

	int (i), (j);
	i = 0;
	j = 0;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return ;
	while (i < data->map_height)
	{
		data->map[i] = malloc(sizeof(char) * (data->map_width + 1));
		ft_memset(data->map[i], '\0', data->map_width + 1);
		line = ft_strtrim(data->null_map[i], "\n");
		while (line && line[j] && j < data->map_width)
		{
			current = line[j];
			if (current == '0' || current == '1' || current == 'N'
				|| current == 'S' || current == 'E' || current == 'W')
			{
				data->map[i][j] = current;
			}
			j++;
		}
		free(line);
		j = 0;
		i++;
	}
	data->map[i] = NULL;
}

int	cp_in_kharita(char *line, t_map *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && i < data->info->last_line_in_map)
	{
		data->null_map[j] = ft_strdup(line);
		j++;
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	return (j);
}

void	player_possitions(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->null_map[i] && i <= data->info->last_line_in_map)
	{
		j = 0;
		while (data->null_map[i][j] && data->null_map[i][j] != '\n')
		{
			if (data->null_map[i][j] == 'W' || data->null_map[i][j] == 'E'
				|| data->null_map[i][j] == 'N' || data->null_map[i][j] == 'S')
			{
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	cp_flkharita(t_map *data)
{
	char	*line;

	int(i), (j), (fd);
	i = 0;
	j = 0;
	fd = open(data->info->file, O_RDONLY);
	data->null_map = malloc(sizeof(char *) * (data->info->height + 1));
	line = get_next_line(fd);
	while (line && i < data->info->first_line_in_map)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	while (!check_empty(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	j = cp_in_kharita(line, data, fd);
	data->null_map[j] = NULL;
	close(fd);
}
