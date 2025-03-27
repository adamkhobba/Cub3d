/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:53:32 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 00:43:22 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_elements(t_map *data)
{
	if (!data)
		return ;
	free(data->info->no_key);
	free(data->no);
	free(data->info->so_key);
	free(data->so);
	free(data->info->we_key);
	free(data->we);
	free(data->info->ea_key);
	free(data->ea);
	free(data->info->c_key);
	free(data->info->c);
	free(data->info->f_key);
	free(data->info->f);
}

void	free_2d(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	handle_colors(char *line, t_map *data)
{
	char	**split;

	int (i), (count), (color);
	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error("Error\nInvalid color\n", data);
	split = ft_split(line, ',');
	if (count_split(split) != 3)
	{
		free_2d(split);
		ft_error("Error\nInvalid color\n", data);
	}
	color = create_trgb(1, ft_atoi00(split[0]), ft_atoi00(split[1]),
			ft_atoi00(split[2]));
	if (color == -1)
	{
		free_2d(split);
		ft_error("Error\nInvalid color\n", data);
	}
	free_2d(split);
	return (color);
}
