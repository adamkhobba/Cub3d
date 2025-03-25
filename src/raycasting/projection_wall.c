/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/25 20:18:19 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	fillceilling_floor(int color, int start, int end)
{
	t_data *data;
	data = get_data();
	for (int i = start; i < end; i++)
	{
			my_put_pixel_to_image(0, i, color);
	}
}

void render_projection_walls(t_ray *rays, int num_rays)
{
    t_data *data;
    int i;
    double wall_strip_h;
    double proj_plane_dis;
    int texture_index;
    unsigned int color;

    i = 0;
    data = get_data();
    proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
    while (i < num_rays)
    {
        rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));
        wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
		fillrect((t_point){i * WALL_STRIP_W, 0},
		WALL_STRIP_W, (data->mlx.win_height - wall_strip_h) / 2, data->map->color_c);
		fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height + wall_strip_h) / 2},
		WALL_STRIP_W, (data->mlx.win_height - wall_strip_h) / 2, data->map->color_f);
        int start_y = (data->mlx.win_height / 2) - (wall_strip_h / 2);
        if (rays[i].was_hit_vertical) {
            if (rays[i].is_ray_facing_left)
                texture_index = 2; // West texture
            else
                texture_index = 3; // East texture
        } else {
            if (rays[i].is_ray_facing_up)
                texture_index = 0; // North texture
            else
                texture_index = 1; // South texture
        }
        int tex_x;
        if (rays[i].was_hit_vertical)
            tex_x = (int)rays[i].wall_hit.y % CUB_SIZE;
        else
            tex_x = (int)rays[i].wall_hit.x % CUB_SIZE;

        tex_x = tex_x * data->textures[texture_index]->width / CUB_SIZE;

        double tex_height = data->textures[texture_index]->height;
        double vertical_scale = tex_height / wall_strip_h;

        for (int y = 0; y < data->mlx.win_height; y++)
        {
            double offset_y = y - start_y;
            if (offset_y >= 0 && offset_y < wall_strip_h)
            {
                int tex_y = (int)(offset_y * vertical_scale);
                tex_y = fmin(tex_y, tex_height - 1);
                color = get_pixel_img(data->textures[texture_index], tex_x, tex_y);
                my_put_pixel_to_image(i * WALL_STRIP_W, y, color);
            }
        }
        i++;
    }
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