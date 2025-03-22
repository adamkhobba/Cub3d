/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:43:24 by csouita           #+#    #+#             */
/*   Updated: 2025/03/22 05:18:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_no_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->no = strdup(split[1]);
	data->info->no_key = strdup(split[0]);
	return (1);
}

int	set_so_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->so = strdup(split[1]);
	data->info->so_key = strdup(split[0]);
	return (1);
}

int	set_we_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->we = strdup(split[1]);
	data->info->we_key = strdup(split[0]);
	return (1);
}

int	set_ea_texture(t_map *data, char **split)
{
	data->info->first_line_in_map++;
	data->ea = strdup(split[1]);
	data->info->ea_key = strdup(split[0]);
	return (1);
}

int	set_floor_and_ceiling_color(t_map *data, char **split, int i)
{
	if (i == 1)
	{
		data->info->first_line_in_map++;
		data->color_f = handle_colors(split[1], data);
		data->info->f = strdup(split[1]);
		data->info->f_key = strdup(split[0]);
	}
	else
	{
		data->info->first_line_in_map++;
		data->color_c = handle_colors(split[1], data);
		data->info->c = strdup(split[1]);
		data->info->c_key = strdup(split[0]);
	}
	return (1);
}
