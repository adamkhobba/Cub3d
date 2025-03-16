/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:39:51 by csouita           #+#    #+#             */
/*   Updated: 2025/03/16 03:00:26 by csouita          ###   ########.fr       */
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
		data->kharita[j] = ft_strdup(line);
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
	while (i <= data->info->last_line_in_map && data->kharita[i])
	{
		j = 0;
		while (data->kharita[i][j] && data->kharita[i][j] != '\n')
		{	
			if (data->kharita[i][j] == 'W' || data->kharita[i][j] == 'E' || data->kharita[i][j] == 'N' || data->kharita[i][j] == 'S')
			{
				data->info->player_in_x = j;
				data->info->player_in_y = i;
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
	data->kharita = malloc(sizeof(char *) * (data->info->height + 1));
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
	data->kharita[j] = NULL;
	close(fd);
}
