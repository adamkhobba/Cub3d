/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 03:55:57 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/12 23:31:21 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(int x, int y)
{
	t_map	*map;

	map = get_data()->map;
	// if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	// 	return (true);
	// if (map->map[y / 32][x / 32] == '1')
	// 	return (true);
	return (false);
}
