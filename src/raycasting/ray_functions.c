/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:43:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 08:02:42 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_render(t_ray *ray, t_data *data)
{
	fillline((t_point){data->player->position.x, data->player->position.y},
		(t_point){data->player->position.x + cos(ray->angle) * 20,
		data->player->position.y + sin(ray->angle) * 20}
		, ray->angle, 0x0000FF);
}

void	rays_many_render(t_ray *rays, int num_rays)
{
	int	i;
	t_data	*data;

	i = 0;
	data = get_data();
	while (i < num_rays)
	{
		ray_render(&rays[i], data);
		i++;
	}
}

t_ray	ray_create(double angle)
{
	t_ray	ray;

	ray.angle = angle;
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.distance = 0;
	ray.was_hit_vertical = 0;
	ray.is_ray_facing_down = ray.angle > 0 && ray.angle < M_PI;
	ray.is_ray_facing_up = !ray.is_ray_facing_down;
	ray.is_ray_facing_right = ray.angle < 0.5 * M_PI || ray.angle > 1.5 * M_PI;
	ray.is_ray_facing_left = !ray.is_ray_facing_right;
	ray.wall_hit_content = 0;
	return (ray);
}