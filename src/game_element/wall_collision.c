/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:55:57 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/13 19:32:18 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(int x, int y)
{
	t_map	*map;
	(void)x;
	(void)y;
	(void)map;

	map = get_data()->map;
	// if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	// 	return (true);
	// if (map->map[y / 32][x / 32] == '1')
	// 	return (true);
	return (false);
}
