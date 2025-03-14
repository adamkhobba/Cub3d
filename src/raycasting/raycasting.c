/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:00:19 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 07:12:58 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int		colum_id;
	int 	i;
	double	ray_angle;
	t_ray	ray;
	double	fov_rad;

	i = 0;
	colum_id = 0;
	fov_rad = degtorad(FOV);
	ray_angle = data->player->rotation_angle - (fov_rad / 2);
	while (i < NUM_RAYS)
	{
		// create an ray
		// cast_ray();
		// render_ray();
		// render_sprite();
		// render_wall();
		ray_angle += fov_rad / NUM_RAYS;
		i++;
		colum_id++;
	}
}