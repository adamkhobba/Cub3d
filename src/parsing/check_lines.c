/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:01:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/04 01:15:59 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	last_line(t_data *data)
{
	int	i;

	i = data->height - 1;
	while (i >= 0)
	{
		if (check_empty(data->map[i]))
		{
			data->last_line_in_map = i;
			break ;
		}
		i--;
	}
	return (1);
}

int	count_len(t_data *data)
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

void	first_line_in_map(t_data *data)
{
	int	i;

	i = data->first_line_in_map;
	while (data->map[i])
	{
		if (data->map[i])
			return ;
		if (!check_empty(data->map[i]))
		{
			data->first_line_in_map++;
			i++;
		}
		else
			i++;
	}
}

int	first_and_last_lines_check(t_data *data)
{
	int	i;
	int	j;

	i = data->first_line_in_map;
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
	i = data->height - 1;
	j = 0;
	return (0);
}
