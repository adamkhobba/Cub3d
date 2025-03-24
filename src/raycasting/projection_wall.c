/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/24 02:05:57 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_img(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y * data->line_len + x
			* (data->bpp / 8))));
}


t_img *initialize_text(t_data *data, char *path)
{
    t_img *text = malloc(sizeof(t_img));
    printf("path: %s\n", path);
    text->img = mlx_xpm_file_to_image(data->mlx.instance, path, &text->width, &text->height);
    if (!text->img)
    {
        ft_putstr_fd("Error\nTexture not found\n", 2);
        exit(1);
    }
    text->addr = mlx_get_data_addr(text->img ,&text->bpp , &text->line_len, &text->endian);
    if (!text->addr)
    {
        ft_putstr_fd("Error\nTexture not found2\n", 2);
        exit(1);
    }
    return text;
}

void init_text(t_data *data)
{
    data->textures[0] = initialize_text(data, data->map->no);
    data->textures[1] = initialize_text(data, data->map->so);
    data->textures[2] = initialize_text(data, data->map->we);
    data->textures[3] = initialize_text(data, data->map->ea);
}


// void render_projection_walls(t_ray *rays, int num_rays)
// {
//     t_data *data;
//     int i;
//     double wall_strip_h;
//     double proj_plane_dis;
//     int texture_index;
//     unsigned int color;
    
//     i = 0;
//     data = get_data();
//     proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
    
//     while (i < num_rays)
//     {
//         rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));
//         wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
//         if (wall_strip_h > data->mlx.win_height)
//             wall_strip_h = data->mlx.win_height;
//         int start_y = (data->mlx.win_height / 2) - (wall_strip_h / 2);
//         if (start_y < 0) 
//             start_y = 0;
//         if (rays[i].was_hit_vertical) {
//             if (rays[i].is_ray_facing_left)
//                 texture_index = 2; // West texture
//             else
//                 texture_index = 3; // East texture
//         } else {
//             if (rays[i].is_ray_facing_up)
//                 texture_index = 0; // North texture
//             else
//                 texture_index = 1; // South texture
//         }
//         int tex_x;
//         if (rays[i].was_hit_vertical)
//             tex_x = (int)rays[i].wall_hit.y % CUB_SIZE;
//         else
//             tex_x = (int)rays[i].wall_hit.x % CUB_SIZE;
//         tex_x = tex_x * data->textures[texture_index]->width / CUB_SIZE;
//         for (int y = 0; y < wall_strip_h && (start_y + y) < data->mlx.win_height; y++)
//         {
//             int tex_y = y * data->textures[texture_index]->height / wall_strip_h;
//             color = get_pixel_img(data->textures[texture_index], tex_x, tex_y);
//             my_put_pixel_to_image(i * WALL_STRIP_W, start_y + y, color);
//         }
//         i++;
//     }
// }

void render_projection_walls(t_ray *rays, int num_rays)
{
    t_data *data;
    int i;
    double wall_strip_h;
    double proj_plane_dis;
    // int *wallTexture;
    double color;
    
    i = 0;
    data = get_data();
    proj_plane_dis = (data->mlx.win_width / (double)2) / tan(degtorad(FOV) / 2);
    // wallTexture = (int *)malloc(sizeof(int) * data->mlx.win_width * data->mlx.win_height);
    // for (int x = 0; x < data->mlx.win_width; x++)
    // {
    //     for (int y = 0; y < data->mlx.win_height; y++)
    //     {
    //         wallTexture[data->mlx.win_width * y + x] = (x % 8 && y % 8) ? 0xFF0000FF : 0xFF000000;
    //     }
    // }
	
    while (i < num_rays)
    {
        rays[i].distance *= cos(normalize_angle(rays[i].angle - data->player->rot_angle));
        
        wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
        if (wall_strip_h > data->mlx.win_height)
            wall_strip_h = data->mlx.win_height;
        
        int start_y = (data->mlx.win_height / 2) - (wall_strip_h / 2);
        if (start_y < 0) 
            start_y = 0;
        
        int x;

        if(rays[i].was_hit_vertical)
            x = (int)rays[i].wall_hit.y % 64;
        else
            x = (int)rays[i].wall_hit.x % 64;

        int tex_x;
        if (rays[i].was_hit_vertical)
            tex_x = (int)rays[i].wall_hit.y % CUB_SIZE;
        else
            tex_x = (int)rays[i].wall_hit.x % CUB_SIZE;
        // tex_x = tex_x * data->textures[0]->width / CUB_SIZE;
        for (int y = 0; y < wall_strip_h && (start_y + y) < data->mlx.win_height; y++)
        {
            // int des = y + (wall_strip_h / 2) - (data->mlx.win_height / 2);
            // int tex_y = (t_pix - ((HEIGHT - wall_h) / 2)) * (TEXTURE_H
			// 	/ wall_h);

            // int distance_from_top = y + (wall_strip_h / 2) - (data->mlx.win_height / 2);
            int tex_y = y * data->textures[0]->height / wall_strip_h ;
            // int  tex_y = distance_from_top * ((float) 64 / wall_strip_h);
            color = get_pixel_img(data->textures[0], tex_x, tex_y);
            my_put_pixel_to_image(i * WALL_STRIP_W, start_y + y, color);
        }
        i++;
    }
    // free(wallTexture);
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