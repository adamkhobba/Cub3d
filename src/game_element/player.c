/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:40:06 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/13 00:07:05 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_player *player)
{
	player->position.x = WIDTH / 2;
	player->position.y = WIDTH / 2;
	player->radius = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = degtorad(90);
	player->walk_speed = 3;
	player->turn_speed = 6 * (M_PI / 180);
}

inline static void	draw_player_direction(t_player *player)
{
	fillline(player->position, (t_point){player->position.x
		+ cos(player->rotation_angle) * 20, player->position.y
		+ sin(player->rotation_angle) * 20}, player->rotation_angle, 0xFF0000);
}

void	put_player(t_player *player)
{
	draw_player_direction(player);
	fillrect((t_point){player->position.x - player->radius,
		player->position.y - player->radius}, player->radius * 2,
		player->radius * 2, 0x00FF00);
}

int	update_player(int keycode)
{
	t_player	*player;
	int			steps;

	player = get_data()->player;
	if (keycode == 119)
		player->walk_direction = 1;
	if (keycode == 115)
		player->walk_direction = -1;
	if (keycode == 97)
		player->turn_direction = -1;
	if (keycode == 100)
		player->turn_direction = 1;
	if (keycode == 65307)
		close_program();
	mlx_destroy_image(get_data()->mlx.instance, get_data()->mlx.image.img);
	player->rotation_angle += player->turn_direction * player->turn_speed;
	steps = player->walk_direction * player->walk_speed;
	player->position.x += cos(player->rotation_angle) * steps;
	player->position.y += sin(player->rotation_angle) * steps;
	if (is_wall(player->position.x, player->position.y))
	{
		player->position.x -= cos(player->rotation_angle) * steps;
		player->position.y -= sin(player->rotation_angle) * steps;
	}
	draw_2dmap(get_data());
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
