/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:57:19 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 23:40:35 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	one_or_zero(char c)
{
	if ((c != '1' && c != '0'))
		return (1);
	return (0);
}

void	validate_player_position(t_map *data, int i, int j, int *count)
{
	if (i == data->info->last_line_in_map || i == data->info->first_line_in_map)
	{
		ft_putstr_fd("Invalid player position\n", 2);
		free_elements(data);
		free_memory(data);
		exit(1);
	}
	data->player_x = i;
	data->player_y = j;
	if (one_or_zero(data->kharita[i + 1][j]) || one_or_zero(data->kharita[i - 1][j])
		|| one_or_zero(data->kharita[i][j + 1]) || one_or_zero(data->kharita[i][j - 1]))
	{
		ft_putstr_fd("Error\nInvalid player position\n", 2);
		free_elements(data);
		free_memory(data);
		exit(1);
	}
	(*count)++;
}

int	check_player_valid_pos(t_map *data)
{
	int (i), (j), (count);
	i = data->info->first_line_in_map;
	count = 0;
	while (i < data->info->height)
	{
		j = 0;
		while (data->kharita[i][j])
		{
			if (data->kharita[i][j] == 'N' || data->kharita[i][j] == 'S'
				|| data->kharita[i][j] == 'E' || data->kharita[i][j] == 'W')
			{
				validate_player_position(data, i, j, &count);
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putstr_fd("Error\nInvalid player position\n", 2);
		free_elements(data);
		free_memory(data);
		exit(1);
	}
	return (0);
}
