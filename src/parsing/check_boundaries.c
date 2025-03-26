/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:36:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/25 21:31:55 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map_cells(t_map *data, int first_line, int last_line)
{
	int	i;
	int	j;

	i = first_line;
	while (i <= last_line)
	{
		j = 0;
		while (data->kharita[i][j])
		{
			if (data->kharita[i][j] == '0')
				check_cell_boundaries(data, i, j);
			j++;
		}
		i++;
	}
}

void	update_map_bounds(t_map *data, int i, int *first_line, int *last_line)
{
	int	line_len;

	if (*first_line == -1)
		*first_line = i;
	*last_line = i;
	line_len = ft_strlen(data->kharita[i]);
	if (data->kharita[i][line_len - 1] == '\n')
		line_len--;
	if (line_len > data->info->boudaries_width)
		data->info->boudaries_width = line_len;
}

void	process_map_line(t_map *data, int i, int *first_line, int *last_line)
{
	int		j;
	char	c;

	j = 0;
	while (data->kharita[i][j])
	{
		c = data->kharita[i][j];
		if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W')
		{
			update_map_bounds(data, i, first_line, last_line);
			break ;
		}
		j++;
	}
}

void	find_map_start(t_map *data, int *first_line, int *last_line)
{
	int	i;

	i = 0;
	*first_line = -1;
	*last_line = -1;
	while (i < data->info->height)
	{
		if (parse_element(data, &i))
		{
			i++;
			continue ;
		}
		process_map_line(data, i, first_line, last_line);
		i++;
	}
}

void	check_boundaries(t_map *data)
{
	int	first_map_line;
	int	last_map_line;

	data->info->boudaries_width = 0;
	find_map_start(data, &first_map_line, &last_map_line);
	data->map_height = last_map_line - first_map_line + 1;
	data->map_width = data->info->boudaries_width;
	validate_map_cells(data, first_map_line, last_map_line);
}
