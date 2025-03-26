/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell_boundaries.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:59:48 by csouita           #+#    #+#             */
/*   Updated: 2025/03/25 23:29:45 by csouita          ###   ########.fr       */
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
	if (!check_empty(data->kharita[i + 1]) || !check_empty(data->kharita[i - 1])
		|| !check_empty(data->kharita[i] + j + 1) || !check_empty(data->kharita[i] + j
			- 1))
	{
		return (0);
	}
	if (i == 0 || i == data->info->height - 1 || j == 0
		|| j == (int)ft_strlen(data->kharita[i]) - 1 || !is_valide(data->kharita[i][j
			+ 1]) || !is_valide(data->kharita[i][j - 1]) || !is_valide(data->kharita[i
			+ 1][j]) || !is_valide(data->kharita[i - 1][j]))
	{
		return (0);
	}
	return (1);
}

void	check_cell_boundaries(t_map *data, int i, int j)
{
	if (data->kharita[i][j] == '0')
	{
		if (!check_neighboring_cells(data, i, j))
		{
			ft_putstr_fd("Error\nMap is not closed1\n", 2);
			free_memory(data);
			exit(1);
			if (i != 0 && i != data->info->height - 1 && j != 0
				&& j != (int)ft_strlen(data->kharita[i]) - 1)
			{
				free_memory(data);
			}
		}
	}
}
