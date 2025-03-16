/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/16 04:26:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_ray ray, int colum_id, t_data *data)
{
	double	xintercept;
	double	yintercept;
	int		xstep;
	int		ystep;
	double	horz_hit_x;
	double	horz_hit_y;
	bool	found_horz_wall_hit;
	int		wall_hit_x;
	int		wall_hit_y;

	// Horizontal Ray-Grid Intersection
	found_horz_wall_hit = false;
	wall_hit_x = 0;
	wall_hit_y = 0;
	colum_id++;
	yintercept = floor(data->player->position.y / CUB_SIZE) * CUB_SIZE;
	// yintercept += ray.is_ray_facing_down * CUB_SIZE;
	yintercept += ray.is_ray_facing_down ? CUB_SIZE : 0;
	xintercept = data->player->position.x
		+ (yintercept - data->player->position.y) / tan(ray.angle);
	ystep = CUB_SIZE;
	ystep *= ray.is_ray_facing_up * -2 + 1; // -->
	// if is_ray_facing_up == 1 then 1 * -2 + 1 ==> -1
	// else 0 * -2 + 1 ==> 1

	xstep = CUB_SIZE / tan(ray.angle);
	xstep *= (ray.is_ray_facing_left && xstep > 0) * -2 + 1;
	xstep *= (ray.is_ray_facing_right && xstep < 0) * -2 + 1;
	horz_hit_x = xintercept;
	horz_hit_y = yintercept;
	if (ray.is_ray_facing_up)
		horz_hit_y--;

	while ((horz_hit_x >= 0 && horz_hit_x <= data->mlx.win_height)
		&& (horz_hit_x >= 0 && horz_hit_x <= data->mlx.win_width))
	{
		if (is_wall(horz_hit_x, horz_hit_y, data))
		{
			found_horz_wall_hit = true;
			wall_hit_x = horz_hit_x;
			wall_hit_y = horz_hit_y;
			fillline((t_point){data->player->position.x, data->player->position.y},
				(t_point){wall_hit_x, wall_hit_y}, ray.angle, 0x00FF00);
			break ;
		}
		else
		{
			horz_hit_x += xstep;
			horz_hit_y += ystep;
		}
	}
	// horizontal_intersection(ray, data);
	// Vertical Ray-Grid Intersection
	// vertical_intersection(ray, data);
}

t_ray	*raycasting(t_data *data)
{
	int		colum_id;
	int		num_rays;
	double	ray_angle;
	t_ray	*rays;
	double	fov_rad;

	colum_id = 0;
	num_rays = data->mlx.win_width / NUM_LARGE;
	rays = malloc(sizeof(t_ray) * num_rays);
	fov_rad = degtorad(FOV);
	ray_angle = data->player->rotation_angle - (fov_rad / 2);
	while (colum_id < 1)
	{
		// create an ray
		rays[colum_id] = ray_create(ray_angle);
		cast_ray(rays[colum_id], colum_id, data);
		// add the ray of rays array
		// rays[colum_id] = ray;
		ray_angle += fov_rad / num_rays;
		colum_id++;
	}
	return (rays);
}
