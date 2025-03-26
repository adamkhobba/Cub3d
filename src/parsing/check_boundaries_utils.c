/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:39:51 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 21:23:58 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_map_array(t_map *data)
{
    int i, j;

    data->null_map = malloc(sizeof(char *) * (data->map_height + 1));
    if (!data->null_map)
        return;
    for (i = 0; i < data->map_height; i++)
    {
        data->null_map[i] = malloc(sizeof(char) * (data->map_width + 1));
        ft_memset(data->null_map[i], '\0', data->map_width + 1);
        for (j = 0; data->map[i] && data->map[i][j] && j < data->map_width; j++)
        {
            char current = data->map[i][j];
            if (current == '0' || current == '1' || 
                current == 'N' || current == 'S' || 
                current == 'E' || current == 'W')
            {
                data->null_map[i][j] = current;
            }
        }
    }
    data->null_map[i] = NULL;
	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			printf("%c", data->null_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

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
