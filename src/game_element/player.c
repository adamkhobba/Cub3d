/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:40:06 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 22:21:56 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_data *data)
{
	data->player->pos.x = data->map->player_x * CUB_SIZE + (CUB_SIZE / 2);
	data->player->pos.y = data->map->player_y * CUB_SIZE + (CUB_SIZE / 2);
	data->player->radius = 3;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	if (data->map->map[data->map->player_y][data->map->player_x] == 'N')
		data->player->rot_angle = degtorad(270);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'S')
		data->player->rot_angle = degtorad(90);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'W')
		data->player->rot_angle = degtorad(180);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'E')
		data->player->rot_angle = degtorad(0);
	data->player->walk_speed = 6;
	data->player->turn_speed = 8 * (M_PI / 180);
}

void	put_player(t_player *player)
{
	if (player == NULL)
		return ;
	fillrect((t_point){(player->pos.x - player->radius) * MINI_MAP,
		(player->pos.y - player->radius) * MINI_MAP}, player->radius * 2
		* MINI_MAP, player->radius * 2 * MINI_MAP, 0x00FF00);
}
