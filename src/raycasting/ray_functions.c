/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:43:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/15 09:15:07 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Normalize an angle to the range [0, 2*PI).
 *
 * This function takes an angle in radians and normalizes it to be within the range
 * [0, 2*PI). If the angle is negative, it adds 2*PI to ensure the result is positive.
 *
 * @param angle The angle in radians to be normalized.
 * @return The normalized angle in the range [0, 2*PI).
 */
double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

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
	(void)num_rays;
	while (i < 0)//num_rays)
	{
		ray_render(&rays[i], data);
		i++;
	}
}

/**
 * @brief Creates a ray with the specified angle and initializes its properties.
 *
 * This function initializes a ray structure with the given angle. It normalizes
 * the angle and sets the initial values for the ray's properties, such as the
 * wall hit coordinates, distance, and direction flags.
 *
 * @param angle The angle of the ray in radians.
 * @return A t_ray structure with the initialized properties.
 */
t_ray	ray_create(double angle)
{
	t_ray	ray;

	ray.angle = normalize_angle(angle);
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