/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:42:15 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 01:42:43 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_input_destroy_img(t_point *steps, t_point move, t_data *data)
{
	mlx_destroy_image(data->mlx.instance, data->mlx.image.img);
	data->player->rot_angle += data->player->turn_direction
		* data->player->turn_speed;
	steps->x = data->player->walk_direction * data->player->walk_speed * move.x;
	steps->y = data->player->walk_direction * data->player->walk_speed * move.y;
}

t_point	cal_move_player(double angle, int direction)
{
	t_point	move;

	move = (t_point){0};
	if (direction == UP || direction == DOWN)
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

int	update_player(int keycode, t_data *data)
{
	t_point	move;
	t_point	steps;

	data->player->walk_direction = 1;
	data->player->rot_angle = normalize_angle(data->player->rot_angle);
	move = (t_point){0};
	if (keycode == UP || keycode == DOWN)
	{
		move = cal_move_player(data->player->rot_angle, UP);
		(keycode == DOWN) && (data->player->walk_direction = -1);
	}
	else if (keycode == RIGHT)
		move = cal_move_player(data->player->rot_angle, RIGHT);
	else if (keycode == LEFT)
		move = cal_move_player(data->player->rot_angle, LEFT);
	(keycode == RIGHT_ARROW) && (data->player->turn_direction = 1);
	(keycode == LEFT_ARROW) && (data->player->turn_direction = -1);
	(keycode == EXIT) && (close_program());
	change_input_destroy_img(&steps, move, data);
	if (!is_wall(data->player->pos.x + steps.x, data->player->pos.y + steps.y))
	{
		data->player->pos.x += steps.x;
		data->player->pos.y += steps.y;
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