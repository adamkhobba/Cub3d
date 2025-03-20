/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/19 23:36:01 by akhobba          ###   ########.fr       */
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
	// printf("data->map->map[y / CUB_SIZE][x / CUB_SIZE]: %p\n", data->map->map[y / CUB_SIZE]);
	if (data->map->map[y_cub][x_cub] == '1')
		return (true);
	return (false);
}
