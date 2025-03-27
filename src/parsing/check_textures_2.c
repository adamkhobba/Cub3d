/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:43:24 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 22:22:47 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_no_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->no = ft_strdup(split[1]);
	data->info->no_key = ft_strdup(split[0]);
	return (1);
}

int	set_so_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->so = ft_strdup(split[1]);
	data->info->so_key = ft_strdup(split[0]);
	return (1);
}

int	set_we_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->we = ft_strdup(split[1]);
	data->info->we_key = ft_strdup(split[0]);
	return (1);
}

int	set_ea_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->ea = ft_strdup(split[1]);
	data->info->ea_key = ft_strdup(split[0]);
	return (1);
}

int	set_floor_and_ceiling_color(t_map *data, char **split, int i)
{
	if (i == 1)
	{
		data->info->first_line_in_map++;
		data->color_f = handle_colors(split[1], data);
		data->info->f = ft_strdup(split[1]);
		data->info->f_key = ft_strdup(split[0]);
	}
	else
	{
		data->info->first_line_in_map++;
		data->color_c = handle_colors(split[1], data);
		data->info->c = ft_strdup(split[1]);
		data->info->c_key = ft_strdup(split[0]);
	}
	return (1);
}
