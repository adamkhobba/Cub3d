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

void	put_player(t_player *player)
{
	if (player == NULL)
		return ;
	fillrect((t_point){(player->position.x - player->radius) * MINI_MAP,
		(player->position.y - player->radius) * MINI_MAP}, player->radius * 2 * MINI_MAP,
		player->radius * 2 * MINI_MAP, 0x00FF00);
}

int	update_player(int keycode)
{
	t_data		*data;
	t_point		move;
	t_point		steps;

	data = get_data();
	data->player->rotation_angle = normalize_angle(data->player->rotation_angle);
	printf("----\n");
	if (keycode == 119)
	{
		data->player->walk_direction = 1;
		move.x = cos(data->player->rotation_angle);
		move.y = sin(data->player->rotation_angle);
	}
	else if (keycode == 115)
	{
		data->player->walk_direction = -1;
		move.x = cos(data->player->rotation_angle);
		move.y = sin(data->player->rotation_angle);
	}
	else if (keycode == 97)
	{
		data->player->walk_direction = 1;
		move.x = -sin(data->player->rotation_angle);
		move.y = cos(data->player->rotation_angle);
	}
	else if (keycode == 100)
	{
		data->player->walk_direction = 1;
		move.x = sin(data->player->rotation_angle);
		move.y = -cos(data->player->rotation_angle);
	}
	else if (keycode == 65363)
		data->player->turn_direction = 1;
	else if (keycode == 65361)
		data->player->turn_direction = -1;
	else if (keycode == 65307)
		close_program();
	mlx_destroy_image(data->mlx.instance, data->mlx.image.img);
	data->player->rotation_angle += data->player->turn_direction
		* data->player->turn_speed;
	steps.x = data->player->walk_direction * data->player->walk_speed * move.x;
	steps.y = data->player->walk_direction * data->player->walk_speed * move.y;
	printf("walk_direction: %d\n", data->player->walk_direction);
	printf("move x: %f, y: %f\n", move.x, move.y);
	printf("steps x: %f, y: %f", steps.x, steps.y);
	if (!is_wall(data->player->position.x + steps.x, data->player->position.y + steps.y,
		data))
	{
		data->player->position.x += steps.x;
		data->player->position.y += steps.y;
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
	else if (keycode == 115)
		player->walk_direction = 0;
	else if (keycode == 97)
		player->walk_direction = 0;
	else if (keycode == 100)
		player->walk_direction = 0;
	else if (keycode == 65363)
		player->turn_direction = 0;
	else if (keycode == 65361)
		player->turn_direction = 0;
	if (keycode == 65307)
		close_program();
	return (0);
}
