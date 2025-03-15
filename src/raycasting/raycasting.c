/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/15 09:10:44 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	cast_ray(t_ray ray, int colum_id, t_data *data)
{
	double	xintercept;
	double	yintercept;
	int		xstep;
	int		ystep;

	colum_id++;
	yintercept = floor(data->player->position.y / CUB_SIZE) * CUB_SIZE;
	yintercept += ray.is_ray_facing_down * CUB_SIZE;
	xintercept = data->player->position.x
		+ (yintercept - data->player->position.y) / tan(ray.angle);
	ystep = CUB_SIZE;
	// if is_ray_facing_up == 1 then 1 * -2 + 1 ==> -1
	// else 0 * -2 + 1 ==> 1
	ystep *= ray.is_ray_facing_up * -2 + 1;
	xstep = CUB_SIZE / tan(ray.angle);
	xstep *= (ray.is_ray_facing_left && xstep > 0) * -2 + 1;
	xstep *= (ray.is_ray_facing_right && xstep < 0) * -2 + 1;

	// Horizontal Ray-Grid Intersection
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
	while (colum_id < num_rays)
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
