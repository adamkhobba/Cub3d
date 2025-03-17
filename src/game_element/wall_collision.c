/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/17 01:19:57 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

bool	is_wall(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->mlx.win_width || y >= data->mlx.win_height)
		return (true);
	if (data->map->map[y / CUB_SIZE][x / CUB_SIZE] == '1')
		return (true);
	return (false);
}
