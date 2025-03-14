/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:37:56 by csouita           #+#    #+#             */
/*   Updated: 2025/03/14 00:35:59 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_element(t_map *data, int *i)
{
	if (ft_strncmp(data->map[*i], "NO", 2) == 0 || ft_strncmp(data->map[*i],
			"SO", 2) == 0 || ft_strncmp(data->map[*i], "WE", 2) == 0
		|| ft_strncmp(data->map[*i], "EA", 2) == 0 || ft_strncmp(data->map[*i],
			"F", 1) == 0 || ft_strncmp(data->map[*i], "C", 1) == 0)
	{
		return (1);
	}
	return (0);
}

int	is_valide2(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	handle_invalid_character_error(t_map *data)
{
	ft_putstr_fd("Error\nInvalid character in map\n", 2);
	free_memory(data);
}

void	check_invalid_character(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->info->height && data->map[i])
	{
		if (parse_element(data, &i))
		{
			i++;
			continue ;
		}
		j = 0;
		while (data->map[i][j])
		{
			if (!is_valide2(data->map[i][j]))
			{
				handle_invalid_character_error(data);
			}
			j++;
		}
		i++;
	}
	check_boundaries(data);
}
