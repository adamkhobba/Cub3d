/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instersection_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:36:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/20 04:29:25 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	horz_intersection(t_data *data , t_ray *ray)
{
	t_point	intercept;
	t_point	step;
	t_point	horz_hit;
	bool	found_horz_wall_hit;
	t_point	horz_wall_hit;
	double	horz_hit_distance;

	// Horizontal Ray-Grid Intersection
	found_horz_wall_hit = false;
	horz_wall_hit.x = 0;
	horz_wall_hit.y = 0;
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
			found_horz_wall_hit = true;
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

