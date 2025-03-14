/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:43:24 by csouita           #+#    #+#             */
/*   Updated: 2025/03/14 00:33:44 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_no_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->no = (split[1]);
	data->info->no_key = (split[0]);
	data->no = (split[1]);
	data->info->no_key = (split[0]);
	return (1);
}

int	set_so_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->so = (split[1]);
	data->info->so_key = (split[0]);
	data->so = (split[1]);
	data->info->so_key = (split[0]);
	return (1);
}

int	set_we_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->we = (split[1]);
	data->info->we_key = (split[0]);
	data->we = (split[1]);
	data->info->we_key = (split[0]);
	return (1);
}

int	set_ea_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->ea = (split[1]);
	data->info->ea_key = (split[0]);
	data->ea = (split[1]);
	data->info->ea_key = (split[0]);
	return (1);
}

int	set_floor_and_ceiling_color(t_map *data, char **split, int i)
{
	if (i == 1)
	{
		data->info->first_line_in_map++;
		data->color_f = handle_colors(split[1], data);
		data->info->f = (split[1]);
		data->info->f_key = (split[0]);
		data->color_f = handle_colors(split[1], data);
		data->info->f = (split[1]);
		data->info->f_key = (split[0]);
	}
	else
	{
		data->info->first_line_in_map++;
		data->color_c = handle_colors(split[1], data);
		data->info->c = (split[1]);
		data->info->c_key = (split[0]);
		data->color_c = handle_colors(split[1], data);
		data->info->c = (split[1]);
		data->info->c_key = (split[0]);
	}
	return (1);
}
