/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 23:36:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
		// cast_ray();
		// add the ray of rays array
		// rays[colum_id] = ray;
		ray_angle += fov_rad / num_rays;
		colum_id++;
	}
	return (rays);
}
