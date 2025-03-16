/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:40:06 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 00:47:55by akhobba          ###   ########.fr       */
/*   Updated: 2025/03/14 00:47:55by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	player_init(t_data *data)
{
	data->player->position.x = data->map->player_x * CUB_SIZE + (CUB_SIZE / 2);
	data->player->position.y = data->map->player_y * CUB_SIZE + (CUB_SIZE / 2);
	data->player->radius = 3;
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->rotation_angle = degtorad(90);
	data->player->walk_speed = 3;
	data->player->turn_speed = 6 * (M_PI / 180);
}

inline static void	draw_player_direction(t_player *player)
{
	fillline(player->position, (t_point){player->position.x
		+ cos(player->rotation_angle) * 20, player->position.y
		+ sin(player->rotation_angle) * 20}, player->rotation_angle, 0xFF0000);
}

void	put_player(t_player *player)
{
	if (player == NULL)
		return ;
	draw_player_direction(player);
	fillrect((t_point){player->position.x - player->radius,
		player->position.y - player->radius}, player->radius * 2,
		player->radius * 2, 0x00FF00);
}

int	update_player(int keycode)
{
	int			steps;
	t_data		*data;
	int			x;
	int			y;

	data = get_data();
	if (keycode == 119)
		data->player->walk_direction = 1;
	else if (keycode == 115)
		data->player->walk_direction = -1;
	else if (keycode == 97)
		data->player->turn_direction = -1;
	else if (keycode == 100)
		data->player->turn_direction = 1;
	else if (keycode == 65307)
		close_program();
	data->player->rotation_angle = normalize_angle(data->player->rotation_angle);
	mlx_destroy_image(data->mlx.instance, data->mlx.image.img);
	data->player->rotation_angle += data->player->turn_direction
		* data->player->turn_speed;
	steps = data->player->walk_direction * data->player->walk_speed;
	x = data->player->position.x;
	y = data->player->position.y;
	data->player->position.x += (int)(cos(data->player->rotation_angle) * steps);
	data->player->position.y += (int)(sin(data->player->rotation_angle) * steps);
	// TODO: improving the code to let the player move next to the wall
	if (is_wall(data->player->position.x, data->player->position.y, data))
	{
		data->player->position.x = x;
		data->player->position.y = y;
	}
	_2dmap_render(data);
	return (0);
}

int	update_player_release(int keycode)
{
	t_player	*player;

	player = get_data()->player;
	if (keycode == 119)
		player->walk_direction = 0;
	if (keycode == 115)
		player->walk_direction = 0;
	if (keycode == 97)
		player->turn_direction = 0;
	if (keycode == 100)
		player->turn_direction = 0;
	if (keycode == 65307)
		close_program();
	return (0);
}
