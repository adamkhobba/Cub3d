/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:43:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 07:44:26 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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