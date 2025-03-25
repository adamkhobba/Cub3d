/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/25 03:45:46 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    i = 0;
    data = get_data();
    proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
    while (i < num_rays)
    {
        rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));
        wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
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

// void render_projection_walls(t_ray *rays, int num_rays)
// {
//     t_data *data;
//     int i;
//     double wall_strip_h;
//     double proj_plane_dis;
//     // int *wallTexture;
//     double color;

//     i = 0;
//     data = get_data();
//     proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
//     // wallTexture = (int *)malloc(sizeof(int) * data->mlx.win_width * data->mlx.win_height);
//     // for (int x = 0; x < data->mlx.win_width; x++)
//     // {
//     //     for (int y = 0; y < data->mlx.win_height; y++)
//     //     {
//     //         wallTexture[data->mlx.win_width * y + x] = (x % 8 && y % 8) ? 0xFF0000FF : 0xFF000000;
//     //     }
//     // }

//     while (i < num_rays)
//     {
//         rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));

//         wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
//         if (wall_strip_h > data->mlx.win_height)
//             wall_strip_h = data->mlx.win_height;

//         int start_y = (data->mlx.win_height / 2) - (wall_strip_h / 2);
//         if (start_y < 0)
//             start_y = 0;

//         int x;

//         if(rays[i].was_hit_vertical)
//             x = (int)rays[i].wall_hit.y % 64;
//         else
//             x = (int)rays[i].wall_hit.x % 64;

//         int tex_x;
//         if (rays[i].was_hit_vertical)
//             tex_x = (int)rays[i].wall_hit.y % CUB_SIZE;
//         else
//             tex_x = (int)rays[i].wall_hit.x % CUB_SIZE;
//         // tex_x = tex_x * data->textures[0]->width / CUB_SIZE;
//         for (int y = 0; y < wall_strip_h && (start_y + y) < data->mlx.win_height; y++)
//         {
//             // int des = y + (wall_strip_h / 2) - (data->mlx.win_height / 2);
//             // int tex_y = (t_pix - ((HEIGHT - wall_h) / 2)) * (TEXTURE_H
// 			// 	/ wall_h);

//             // int distance_from_top = y + (wall_strip_h / 2) - (data->mlx.win_height / 2);
//             int tex_y = y * data->textures[0]->height / wall_strip_h ;
//             // int  tex_y = distance_from_top * ((float) 64 / wall_strip_h);
//             color = get_pixel_img(data->textures[0], tex_x, tex_y);
//             my_put_pixel_to_image(i * WALL_STRIP_W, start_y + y, color);
//         }
//         i++;
//     }
//     // free(wallTexture);
// }

// cub_size = l3ard dyal cub
// wall_strip_h = tol dyal hit
// proj_plane_dis = distance dyal projection plane
// top pixel y =  (win_height / 2) - (wall_strip_h / 2)
// top pixel x = i * WALL_STRIP_W
// bottom pixel y = (win_height / 2) + (wall_strip_h / 2)
// bottom pixel x = i * WALL_STRIP_W
// window width = data->mlx.win_width
// window height = data->mlx.win_height