/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:39:51 by csouita           #+#    #+#             */
/*   Updated: 2025/03/21 23:40:02 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cp_in_kharita(char *line, t_map *data, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && i < data->info->last_line_in_map)
	{
		data->map[j] = ft_strdup(line);
		j++;
		if (line)
			free(line);
		line = get_next_line(fd);
		i++;
	}
	return (j);
}

void player_possitions(t_map *data)
{
	int i = 0;
	int j = 0;

	while (data->map[i] && i <= data->info->last_line_in_map)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == 'W' || data->map[i][j] == 'E' || data->map[i][j] == 'N' || data->map[i][j] == 'S')
			{
				data->player_x = j;
				data->player_y= i;
			}
			j++;
		}
		i++;
	}
}

void	cp_flkharita(t_map *data)
{
	char	*line;

	int (i), (j), (fd);
	i = 0;
	j = 0;
	fd = open(data->info->file, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->info->height + 1));
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
	data->map[j] = NULL;
	close(fd);
}
