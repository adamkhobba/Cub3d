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
	if (data->map->map[data->map->player_y][data->map->player_x] == 'N')
		data->player->rotation_angle = degtorad(270);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'S')
		data->player->rotation_angle = degtorad(90);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'W')
		data->player->rotation_angle = degtorad(180);
	else if (data->map->map[data->map->player_y][data->map->player_x] == 'E')
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

t_point	cal_move_player(double angle, int direction)
{
	t_point	move;

	move = (t_point){0};
	if (direction == UP)
	{
		move.x = cos(angle);
		move.y = sin(angle);
	}
	else if (direction == DOWN)
	{
		move.x = cos(angle);
		move.y = sin(angle);
	}
	else if (direction == RIGHT)
	{
		move.x = -sin(angle);
		move.y = cos(angle);
	}
	else if (direction == LEFT)
	{
		move.x = sin(angle);
		move.y = -cos(angle);
	}
	return (move);
}

int	update_player(int keycode)
{
	t_data		*data;
	t_point		move;
	t_point		steps;

	data = get_data();
	data->player->rotation_angle = normalize_angle(data->player->rotation_angle);
	if (keycode == UP)
	{
		data->player->walk_direction = 1;
		// move = cal_move_player(data->player->rotation_angle, UP);
		move.x = cos(data->player->rotation_angle);
		move.y = sin(data->player->rotation_angle);
		printf("move.y = %f move.x = %f\n", move.y, move.x);
	}
	else if (keycode == DOWN)
	{
		data->player->walk_direction = -1;
		move = cal_move_player(data->player->rotation_angle, DOWN);
	}
	else if (keycode == RIGHT)
	{
		data->player->walk_direction = 1;
		move = cal_move_player(data->player->rotation_angle, RIGHT);
	}
	else if (keycode == LEFT)
	{
		move = cal_move_player(data->player->rotation_angle, LEFT);
		data->player->walk_direction = 1;
	}
	(keycode == RIGHT_ARROW) && (data->player->turn_direction = 1);
	(keycode == LIFGHT_ARROW) && (data->player->turn_direction = -1);
	(keycode == 65307) && close_program();
	mlx_destroy_image(data->mlx.instance, data->mlx.image.img);
	data->player->rotation_angle += data->player->turn_direction
		* data->player->turn_speed;
	steps.x = data->player->walk_direction * data->player->walk_speed * move.x;
	steps.y = data->player->walk_direction * data->player->walk_speed * move.y;
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
