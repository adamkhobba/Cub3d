/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:36:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/14 00:27:43 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_valide(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_neighboring_cells(t_map *data, int i, int j)
{
	if (!check_empty(data->map[i + 1]) || !check_empty(data->map[i - 1])
		|| !check_empty(data->map[i] + j + 1) || !check_empty(data->map[i] + j
			- 1))
	{
		return (0);
	}
	if (i == 0 || i == data->info->height - 1 || j == 0
		|| j == (int)ft_strlen(data->map[i]) - 1 || !is_valide(data->map[i][j
			+ 1]) || !is_valide(data->map[i][j - 1]) || !is_valide(data->map[i
			+ 1][j]) || !is_valide(data->map[i - 1][j]))
	{
		return (0);
	}
	return (1);
}

void	check_cell_boundaries(t_map *data, int i, int j)
{
	if (data->map[i][j] == '0')
	{
		if (!check_neighboring_cells(data, i, j))
		{
			ft_putstr_fd("Error\nMap is not closed\n", 2);
			free_memory(data);
			if (i != 0 && i != data->info->height - 1 && j != 0
				&& j != (int)ft_strlen(data->map[i]) - 1)
			{
				free_memory(data);
			}
		}
	}
}

void check_boundaries(t_map *data)
{
    int (i), (j) , (width) , (first_map_line) , (last_map_line) , (height) , (line_len);

    first_map_line = -1;
    last_map_line = -1;
    width = 0;
    i = 0;
    while (i < data->info->height)
    {
        if (parse_element(data, &i))
        {
            i++;
            continue;
        }
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '1' || data->map[i][j] == '0' || 
                data->map[i][j] == 'N' || data->map[i][j] == 'S' || 
                data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                if (first_map_line == -1)
                    first_map_line = i;
                last_map_line = i;
                line_len = ft_strlen(data->map[i]) ;
                if (data->map[i][line_len - 1] == '\n')
                    line_len--;
                if (line_len > width)
                    width = line_len;
                break;
            }
            j++;
        }
        i++;
    }
    height = (last_map_line - first_map_line + 1);
    for (i = first_map_line; i <= last_map_line; i++)
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')  
                check_cell_boundaries(data, i, j);
            j++;
        }
    }
    data->map_height = height;
    data->map_width = width;
}
