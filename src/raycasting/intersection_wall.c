/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:36:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/20 12:34:29 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	horz_intersection(t_data *data , t_ray *ray)
{
	t_point	intercept;
	t_point	step;
	t_point	horz_hit;
	t_point	horz_wall_hit;

	// Horizontal Ray-Grid Intersection
	horz_wall_hit.x = INT_MAX;
	horz_wall_hit.y = INT_MAX;
	intercept.y = floor(data->player->position.y / CUB_SIZE) * CUB_SIZE;
	intercept.y += ray->is_ray_facing_down * CUB_SIZE;
	intercept.x = data->player->position.x
		+ (intercept.y - data->player->position.y) / tan(ray->angle);
	step.y = CUB_SIZE;
	step.y *= ray->is_ray_facing_up * -2 + 1;
	step.x = CUB_SIZE / tan(ray->angle);
	step.x *= (ray->is_ray_facing_left && step.x > 0) * -2 + 1;
	step.x *= (ray->is_ray_facing_right && step.x < 0) * -2 + 1;
	horz_hit.x = intercept.x;
	horz_hit.y = intercept.y;
	if (ray->is_ray_facing_up)
		horz_hit.y -= 0.00001;
	while ((horz_hit.x >= 0 && horz_hit.x < data->map->map_width * CUB_SIZE)
		&& (horz_hit.y >= 0 && horz_hit.y < data->map->map_height * CUB_SIZE))
	{
		if (is_wall(horz_hit.x, horz_hit.y, data))
		{
			horz_wall_hit.x = horz_hit.x;
			horz_wall_hit.y = horz_hit.y;
			break ;
		}
		else
		{
			horz_hit.x += step.x;
			horz_hit.y += step.y;
		}
	}
	return (horz_wall_hit);
}


t_point	vert_intersection(t_data *data, t_ray *ray)
{
	t_point	intercept;
	t_point	step;
	t_point	vert_hit;
	t_point	vert_wall_hit;

	vert_wall_hit.x = 0;
	vert_wall_hit.y = 0;
	intercept.x = floor(data->player->position.x / CUB_SIZE) * CUB_SIZE;
	intercept.x += ray->is_ray_facing_right * CUB_SIZE;
	intercept.y = data->player->position.y
		+ (intercept.x - data->player->position.x) * tan(ray->angle);
	step.x = CUB_SIZE;
	step.x *= ray->is_ray_facing_left * -2 + 1;
	step.y = CUB_SIZE * tan(ray->angle);
	step.y *= (ray->is_ray_facing_up && step.y > 0) * -2 + 1;
	step.y *= (ray->is_ray_facing_down && step.y < 0) * -2 + 1;
	vert_hit.x = intercept.x;
	vert_hit.y = intercept.y;
	if (ray->is_ray_facing_left)
		vert_hit.x -= 0.00001;
	while((vert_hit.x >= 0 && vert_hit.x < data->map->map_width * CUB_SIZE)
		&& (vert_hit.y >= 0 && vert_hit.y < data->map->map_height * CUB_SIZE))
	{
		if (is_wall(vert_hit.x, vert_hit.y, data))
		{
			vert_wall_hit.x = vert_hit.x;
			vert_wall_hit.y = vert_hit.y;
			break ;
		}
		else
		{
			vert_hit.x += step.x;
			vert_hit.y += step.y;
		}
	}
	return (vert_wall_hit);
}

// void	cast_ray(t_ray *ray, t_data *data)
// {
// 	double	horz_hit_distance;
// 	double	vert_hit_distance;
// 	t_point	horz_wall_hit;
// 	t_point	vert_wall_hit;

// 	horz_wall_hit = horz_intersection(data, ray);
// 	vert_wall_hit = vert_intersection(data, ray);
// 	if(horz_wall_hit.x != INT_MAX && horz_wall_hit.y != INT_MAX)
// 		horz_hit_distance = cal_distance((t_point){data->player->position.x, data->player->position.y},
// 			(t_point){horz_wall_hit.x, horz_wall_hit.y});
// 	else
// 		horz_hit_distance = INT_MAX;
// 	if (vert_wall_hit.x != INT_MAX && vert_wall_hit.y != INT_MAX)
// 		vert_hit_distance = cal_distance((t_point){data->player->position.x, data->player->position.y},
// 			(t_point){vert_wall_hit.x, vert_wall_hit.y});
// 	else
// 		vert_hit_distance = INT_MAX;
// 	if (horz_hit_distance < vert_hit_distance - 0.01)
// 	{
// 		ray->wall_hit_x = horz_wall_hit.x;
// 		ray->wall_hit_y = horz_wall_hit.y;
// 		ray->distance = horz_hit_distance;
// 		ray->was_hit_vertical = false;
// 	}
// 	else
// 	{
// 		ray->wall_hit_x = vert_wall_hit.x;
// 		ray->wall_hit_y = vert_wall_hit.y;
// 		ray->distance = vert_hit_distance;
// 		ray->was_hit_vertical = true;
// 	}
// }