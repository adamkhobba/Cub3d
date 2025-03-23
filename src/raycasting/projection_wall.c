/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/23 02:10:21 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_projection_walls(t_ray *rays, int num_rays)
{
    t_data *data;
    int i;
    double wall_strip_h;
    double proj_plane_dis;
    int *wallTexture;
    
    i = 0;
    data = get_data();
    proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
    wallTexture = (int *)malloc(sizeof(int) * data->mlx.win_width * data->mlx.win_height);
    for (int x = 0; x < data->mlx.win_width; x++)
    {
        for (int y = 0; y < data->mlx.win_height; y++)
        {
            wallTexture[data->mlx.win_width * y + x] = (x % 8 && y % 8) ? 0xFF0000FF : 0xFF000000;
        }
    }


	
    while (i < num_rays)
    {
        rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));
        
        wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
        if (wall_strip_h > data->mlx.win_height)
            wall_strip_h = data->mlx.win_height;
        
        int start_y = (data->mlx.win_height / 2) - (wall_strip_h / 2);
        if (start_y < 0) 
            start_y = 0;
            
        for (int y = 0; y < wall_strip_h && (start_y + y) < data->mlx.win_height; y++)
        {
            int tex_y = (y * data->mlx.win_height) / wall_strip_h;
            
            int color;
            if (rays[i].was_hit_vertical)
            {
                int tex_x = (int)(rays[i].wall_hit.y) % data->mlx.win_width;
                color = wallTexture[data->mlx.win_width * tex_y + tex_x];
            }
            else
            {
                int tex_x = (int)(rays[i].wall_hit.x) % data->mlx.win_width;
                color = wallTexture[data->mlx.win_width * tex_y + tex_x];
            }   
            my_put_pixel_to_image(i * WALL_STRIP_W, start_y + y, color);
        }
        i++;
    }
    free(wallTexture);
}

// cub_size = l3ard dyal cub
// wall_strip_h = tol dyal hit
// proj_plane_dis = distance dyal projection plane
// top pixel y =  (win_height / 2) - (wall_strip_h / 2)
// top pixel x = i * WALL_STRIP_W
// bottom pixel y = (win_height / 2) + (wall_strip_h / 2)
// bottom pixel x = i * WALL_STRIP_W
// window width = data->mlx.win_width	
// window height = data->mlx.win_height