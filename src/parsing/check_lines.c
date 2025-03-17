/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:01:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/17 00:37:27 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	last_line(t_map *data)
{
	int	i;

	i = data->info->height - 1;
	while (i >= 0)
	{
		if (check_empty(data->kharita[i]))
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
	if (!data->kharita)
		return (0);
	while (data->kharita[i])
	{
		if (check_empty(data->kharita[i]))
			count += ft_strlen(data->kharita[i]);
		i++;
	}
	return (count);
}

void	first_line_in_map(t_map *data)
{
	int	i;

	i = data->info->first_line_in_map;
	while (data->kharita[i])
	{
		if (data->kharita[i])
			return ;
		if (!check_empty(data->kharita[i]))
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
	while (data->kharita[i][j])
	{
		if (data->kharita[i][j] != '1' && (data->kharita[i][j] != ' '
				&& (!(data->kharita[i][j] >= 9 && data->kharita[i][j] <= 13)))
			&& data->kharita[i][j] != '\n')
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
