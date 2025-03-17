/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/17 00:40:02 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

bool	is_wall(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->mlx.win_width || y >= data->mlx.win_height)
		return (true);
	printf("x / 32: %d\n", x / 32);
	printf("y / 32: %d\n", y / 32);
	printf("data->map->map[y / 32][x / 32]: %c\n", data->map->map[y / 32][x / 32]);
	if (data->map->map[y / 32][x / 32] == '1')
		return (true);
	return (false);
}
