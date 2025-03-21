/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 01:35:23 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_projection_walls(t_ray *rays, int num_rays)
{
	double	wall_strip_h;
	int		i;
	double	proj_plane_dis;
	t_data	*data;

	i = 0;
	data = get_data();
	wall_strip_h = 0;
	proj_plane_dis = (data->mlx.win_width / 2) / tan(degtorad(FOV) / 2);
	while (i < num_rays)
	{
		rays[i].distance *= cos(normalize_angle(rays[i].angle
					- data->player->rot_angle));
		wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
		if (wall_strip_h > data->mlx.win_height)
			wall_strip_h = data->mlx.win_height;
		if (rays[i].was_hit_vertical)
			fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height / 2)
				- (wall_strip_h / 2)}, WALL_STRIP_W, wall_strip_h, 0x0000FF);
		else
			fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height / 2)
				- (wall_strip_h / 2)}, WALL_STRIP_W, wall_strip_h, 0x00FF00);
		i++;
	}
}
