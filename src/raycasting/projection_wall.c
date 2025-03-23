/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/03/23 00:57:20 by csouita          ###   ########.fr       */
=======
/*   Updated: 2025/03/23 00:55:12 by csouita          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_projection_walls(t_ray *rays, int num_rays)
{
	t_data	*data;
	int		*wallTexture;

	i = 0.0;
	data = get_data();
	wall_strip_height = 0;
	proj_plane_distance = (data->mlx.win_width / (double)2)  * tan(degtorad(FOV) / 2);

	wallTexture = (int *)malloc(sizeof(int) * (int)wall_strip_height * WALL_STRIP_WIDTH);
	// for(int x = 0; x < WALL_STRIP_WIDTH; x++)
	// {
	// 	for(int y = 0; y < (int)wall_strip_height; y++)
	// 	{
	// 		wallTexture[((int)wall_strip_height * y) + x ] = (x % 8 && y % 8 ) ? 0xFF0000FF : 0xFF000000;
	// 	}
	// }


	// for(int y  = )
	
	// printf("width %d\n", data->mlx.win_width);
	while (i < num_rays)
	{
		rays[i].distance *= cos(normalize_angle(rays[i].angle
					- data->player->rot_angle));
		wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
		if (wall_strip_h > data->mlx.win_height)
			wall_strip_h = data->mlx.win_height;
		if (rays[i].was_hit_vertical)
			fillrect((t_point){i * WALL_STRIP_WIDTH, (data->mlx.win_height / 2)
				- (wall_strip_height / 2)},
				WALL_STRIP_WIDTH, wall_strip_height, 0x0000FF);  /// x
		else
			fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height / 2)
				- (wall_strip_h / 2)}, WALL_STRIP_W, wall_strip_h, 0x00FF00);
		i++;
	}
}
