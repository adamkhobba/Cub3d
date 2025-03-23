/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 23:30:26 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Casts a ray and determines the closest wall hit point, distance,
 *        and whether the hit was vertical or horizontal.
 *
 * This function calculates the horizontal and vertical wall intersections
 * for a given ray and determines which intersection is closer to the player's
 * pos. It updates the ray's properties with the closest wall hit point,
 * the distance to the wall, and whether the hit was vertical or horizontal.
 *
 * @param ray A pointer to the t_ray structure representing the ray being cast.
 *            This structure will be updated with the results of the raycasting.
 * @param data A pointer to the t_data structure containing the game state,
 *             including the player's position and other relevant data.
 */
void	cast_ray(t_ray *ray, t_data *data)
{
	double	horz_hit_distance;
	double	vert_hit_distance;
	t_point	horz_wall_hit;
	t_point	vert_wall_hit;

	horz_wall_hit = horz_intersection(data, ray);
	vert_wall_hit = vert_intersection(data, ray);
	if (horz_wall_hit.x != INT_MAX && horz_wall_hit.y != INT_MAX)
		horz_hit_distance = cal_distance(data->player->pos, horz_wall_hit);
	else
		horz_hit_distance = INT_MAX;
	if (vert_wall_hit.x != INT_MAX && vert_wall_hit.y != INT_MAX)
		vert_hit_distance = cal_distance(data->player->pos, vert_wall_hit);
	else
		vert_hit_distance = INT_MAX;
	if (horz_hit_distance < vert_hit_distance - 0.00001)
	{
		ray->wall_hit = horz_wall_hit;
		ray->distance = horz_hit_distance;
		ray->was_hit_vertical = false;
		return ;
	}
	ray->wall_hit = vert_wall_hit;
	ray->distance = vert_hit_distance;
	ray->was_hit_vertical = true;
}

/**
 * @brief Performs raycasting to generate an array of rays based on the player's
 *        position and field of view (FOV).
 *
 * This function calculates the direction of each ray within the player's FOV
 * and casts the rays to detect intersections with the environment. The rays
 * are stored in an array, which is dynamically allocated and returned to the
 * caller.
 *
 * @param data Pointer to the main data structure containing the player's
 *             position, rotation angle, and other game-related information.
 * @param num_rays The number of rays to cast, which determines the resolution
 *                 of the raycasting.
 *
 * @return A pointer to an array of t_ray structures representing the cast rays.
 *         Returns NULL if memory allocation for the array fails.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       returned array of rays.
 */
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
	ray_angle = data->player->rot_angle - (fov_rad / (double)2);
	while (colum_id < num_rays)
	{
		rays[colum_id] = ray_create(ray_angle);
		cast_ray(&rays[colum_id], data);
		ray_angle += fov_rad / num_rays;
		colum_id++;
	}
	return (rays);
}
