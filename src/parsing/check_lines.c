/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:01:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/14 00:35:24 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	last_line(t_map *data)
{
	int	i;

	i = data->info->height - 1;
	while (i >= 0)
	{
		if (check_empty(data->map[i]))
		{
			data->info->last_line_in_map = i;
			break ;
		}
		i--;
	}
	return (1);
}

int	count_len(t_map *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
	{
		if (check_empty(data->map[i]))
			count += ft_strlen(data->map[i]);
		i++;
	}
	return (count);
}

void	first_line_in_map(t_map *data)
{
	int	i;

	i = data->info->first_line_in_map;
	while (data->map[i])
	{
		if (data->map[i])
			return ;
		if (!check_empty(data->map[i]))
		{
			data->info->first_line_in_map++;
			i++;
		}
		else
			i++;
	}
}

int	first_and_last_lines_check(t_map *data)
{
	int	i;
	int	j;

	i = data->info->first_line_in_map;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1' && (data->map[i][j] != ' '
				&& (!(data->map[i][j] >= 9 && data->map[i][j] <= 13)))
			&& data->map[i][j] != '\n')
		{
			ft_putstr_fd("Error\nMap is not clossssssssssed\n", 2);
			return (1);
		}
		j++;
	}
	i = data->info->height - 1;
	j = 0;
	return (0);
}
