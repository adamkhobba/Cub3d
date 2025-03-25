/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:40:20 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/25 16:04:15 by akhobba          ###   ########.fr       */
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
	if (x < 0 || y < 0 || x >= data->mlx.win_width || y >= data->mlx.win_height)
		return (true);
	if (data->map->map[y_cub][x_cub] == '1')
		return (true);
	return (false);
}
