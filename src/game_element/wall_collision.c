/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/14 05:37:03 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

bool	is_wall(int x, int y)
{
	t_map	*map;

	map = get_data()->map;
	if (x < 0 || y < 0 || x >= map->map_width || y >= map->map_height)
		return (true);
	if (map->map[y / 32][x / 32] == '1')
		return (true);
	return (false);
}
