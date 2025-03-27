/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:40:20 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/27 01:01:52 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(int x, int y)
{
	t_data	*data;
	int		x_cub;
	int		y_cub;

	data = get_data();
	x_cub = floor(x / CUB_SIZE);
	y_cub = floor(y / CUB_SIZE);
	if (x < 0 || y < 0 || x_cub >= data->map->map_width
		|| y_cub >= data->map->map_height)
		return (true);
	if (data->map->null_map[y_cub][x_cub] == '1')
		return (true);
	return (false);
}
