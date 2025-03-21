/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:36:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 22:21:15 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	horz_intersection(t_data *data, t_ray *ray)
{
	t_point	intercept;
	t_point	step;
	t_point	horz_wall_hit;

	horz_wall_hit = (t_point){INT_MAX, INT_MAX};
	intercept.y = floor(data->player->pos.y / CUB_SIZE) * CUB_SIZE;
	intercept.y += ray->is_ray_facing_down * CUB_SIZE;
	intercept.x = data->player->pos.x
		+ (intercept.y - data->player->pos.y) / tan(ray->angle);
	step.y = CUB_SIZE * (ray->is_ray_facing_up * -2 + 1);
	step.x = CUB_SIZE / tan(ray->angle);
	step.x *= (ray->is_ray_facing_left && step.x > 0) * -2 + 1;
	step.x *= (ray->is_ray_facing_right && step.x < 0) * -2 + 1;
	(ray->is_ray_facing_up) && (intercept.y -= 0.00001);
	while ((intercept.x >= 0 && intercept.x < data->map->map_width * CUB_SIZE)
		&& (intercept.y >= 0 && intercept.y < data->map->map_height * CUB_SIZE))
	{
		if (is_wall(intercept.x, intercept.y))
			return (horz_wall_hit = intercept);
		intercept.x += step.x;
		intercept.y += step.y;
	}
	return (horz_wall_hit);
}

t_point	vert_intersection(t_data *data, t_ray *ray)
{
	t_point	intercept;
	t_point	step;
	t_point	vert_wall_hit;

	vert_wall_hit = (t_point){INT_MAX, INT_MAX};
	intercept.x = floor(data->player->pos.x / CUB_SIZE) * CUB_SIZE;
	intercept.x += ray->is_ray_facing_right * CUB_SIZE;
	intercept.y = data->player->pos.y
		+ (intercept.x - data->player->pos.x) * tan(ray->angle);
	step.x = CUB_SIZE * (ray->is_ray_facing_left * -2 + 1);
	step.y = CUB_SIZE * tan(ray->angle);
	step.y *= (ray->is_ray_facing_up && step.y > 0) * -2 + 1;
	step.y *= (ray->is_ray_facing_down && step.y < 0) * -2 + 1;
	(ray->is_ray_facing_left) && (intercept.x -= 0.00001);
	while ((intercept.x >= 0 && intercept.x < data->map->map_width * CUB_SIZE)
		&& (intercept.y >= 0 && intercept.y < data->map->map_height * CUB_SIZE))
	{
		if (is_wall(intercept.x, intercept.y))
			return (vert_wall_hit = intercept);
		intercept.x += step.x;
		intercept.y += step.y;
	}
	return (vert_wall_hit);
}
