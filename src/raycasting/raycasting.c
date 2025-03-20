/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/17 01:26:58by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_ray *ray, t_data *data)
{
	double	xintercept;
	double	yintercept;
	double		xstep;
	double		ystep;
	double	horz_hit_x;
	double	horz_hit_y;
	bool	found_horz_wall_hit;
	double	horz_wall_hit_x;
	double	horz_wall_hit_y;

	// Horizontal Ray-Grid Intersection
	found_horz_wall_hit = false;
	horz_wall_hit_x = 0;
	horz_wall_hit_y = 0;
	yintercept = floor(data->player->position.y / CUB_SIZE) * CUB_SIZE;
	yintercept += ray->is_ray_facing_down * CUB_SIZE;
	xintercept = data->player->position.x
		+ (yintercept - data->player->position.y) / tan(ray->angle);
	ystep = CUB_SIZE;
	ystep *= ray->is_ray_facing_up * -2 + 1;
	xstep = CUB_SIZE / tan(ray->angle);
	xstep *= (ray->is_ray_facing_left && xstep > 0) * -2 + 1;
	xstep *= (ray->is_ray_facing_right && xstep < 0) * -2 + 1;
	horz_hit_x = xintercept;
	horz_hit_y = yintercept;
	if (ray->is_ray_facing_up)
		horz_hit_y -= 0.00001;
	// printf("horz\n");
	// printf ("step %d %d\n", xstep, ystep);
	while ((horz_hit_x >= 0 && horz_hit_x < data->mlx.win_width)
		&& (horz_hit_y >= 0 && horz_hit_y < data->mlx.win_height))
	{
		// printf("Y %d X %d\n", (int)floor(horz_hit_y / CUB_SIZE),
		// (int)floor(horz_hit_x / CUB_SIZE));
		// printf("horz_hit_x %f horz_hit_y %f map %c\n", horz_hit_x, horz_hit_y, data->map->map[(int)floor(horz_hit_y / CUB_SIZE)]
		// [(int)floor(horz_hit_x / CUB_SIZE)]);
		if (is_wall(horz_hit_x, horz_hit_y, data))
		{
			found_horz_wall_hit = true;
			horz_wall_hit_x = horz_hit_x;
			horz_wall_hit_y = horz_hit_y;

			break ;
		}
		else
		{
			horz_hit_x += xstep;
			horz_hit_y += ystep;
		}
	}
	// printf("--------------------\n");
	// Vertical Ray-Grid Intersection
	double	vert_hit_x;
	double	vert_hit_y;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	bool	found_vert_wall_hit;

	vert_wall_hit_x = 0;
	vert_wall_hit_y = 0;
	xintercept = floor(data->player->position.x / CUB_SIZE) * CUB_SIZE;
	xintercept += ray->is_ray_facing_right * CUB_SIZE;
	found_vert_wall_hit = false;
	yintercept = data->player->position.y
		+ (xintercept - data->player->position.x) * tan(ray->angle);
	xstep = CUB_SIZE;
	xstep *= ray->is_ray_facing_left * -2 + 1;
	ystep = CUB_SIZE * tan(ray->angle);
	ystep *= (ray->is_ray_facing_up && ystep > 0) * -2 + 1;
	ystep *= (ray->is_ray_facing_down && ystep < 0) * -2 + 1;
	vert_hit_x = xintercept;
	vert_hit_y = yintercept;
	if (ray->is_ray_facing_left)
		vert_hit_x -= 0.00001;
	// printf("vert\n");
	// printf ("step %d %d\n", xstep, ystep);
	while((vert_hit_x >= 0 && vert_hit_x < data->mlx.win_width)
		&& (vert_hit_y >= 0 && vert_hit_y < data->mlx.win_height))
		{
		// printf("Y %d X %d\n", (int)floor(vert_hit_y / CUB_SIZE),
		// (int)floor(vert_hit_x / CUB_SIZE));
		// printf("vert_hit_x %f vert_hit_y %f map %c\n", vert_hit_x, vert_hit_y, data->map->map[(int)floor(vert_hit_y / CUB_SIZE)]
		// [(int)floor(vert_hit_x / CUB_SIZE)]);
		if (is_wall(vert_hit_x, vert_hit_y, data))
		{
			// printf ("found\n");
			found_vert_wall_hit = true;
			vert_wall_hit_x = vert_hit_x;
			vert_wall_hit_y = vert_hit_y;
			break ;
		}
		else
		{
			vert_hit_x += xstep;
			vert_hit_y += ystep;
		}
	}
	// printf("----------end----------\n");
	// Calculate both horizontal and vertical distances and choose the smallest one
	double	horz_hit_distance;
	double	vert_hit_distance;

	if(found_horz_wall_hit)
		horz_hit_distance = cal_distance((t_point){data->player->position.x, data->player->position.y},
			(t_point){horz_wall_hit_x, horz_wall_hit_y});
	else
		horz_hit_distance = INT_MAX;
	if(found_vert_wall_hit)
		vert_hit_distance = cal_distance((t_point){data->player->position.x, data->player->position.y},
			(t_point){vert_wall_hit_x, vert_wall_hit_y});
	else
		vert_hit_distance = INT_MAX;
	if (horz_hit_distance < vert_hit_distance - 0.01)
	{
		ray->wall_hit_x = horz_wall_hit_x;
		ray->wall_hit_y = horz_wall_hit_y;
		ray->distance = horz_hit_distance;
		ray->was_hit_vertical = false;
	}
	else
	{
		ray->wall_hit_x = vert_wall_hit_x;
		ray->wall_hit_y = vert_wall_hit_y;
		ray->distance = vert_hit_distance;
		ray->was_hit_vertical = true;
	}
}

t_ray	*raycasting(t_data *data, int num_rays)
{
	t_ray	*rays;
	double	ray_angle;
	double	fov_rad;
	int		colum_id;

	colum_id = 0;
	rays = malloc(sizeof(t_ray) * num_rays);
	if (!rays)
		return (NULL);
	fov_rad = degtorad(FOV);
	ray_angle = data->player->rotation_angle - (fov_rad / (double)2);
	while (colum_id < num_rays)
	{
		rays[colum_id] = ray_create(ray_angle);
		cast_ray(&rays[colum_id], data);
		ray_angle += fov_rad / num_rays;
		colum_id++;
	}
	return (rays);
}
