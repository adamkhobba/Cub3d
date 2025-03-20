/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/20 04:05:29 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

bool	is_wall(int x, int y, t_data *data)
{
	int x_cub;
	int y_cub;

	x_cub = floor(x / CUB_SIZE);
	y_cub = floor(y / CUB_SIZE);
	if (x < 0 || y < 0 || x >= data->mlx.win_width || y >= data->mlx.win_height)
		return (true);
	if (data->map->map[y_cub][x_cub] == '1')
		return (true);
	return (false);
}
