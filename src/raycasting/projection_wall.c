/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/27 15:49:59 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture_index(t_ray *rays, int i)
{
	if (rays[i].was_hit_vert)
	{
		if (rays[i].is_ray_facing_left)
			return (2);
		else
			return (3);
	}
	else
	{
		if (rays[i].is_ray_facing_up)
			return (0);
		else
			return (1);
	}
}

void	put_texture_color(t_data *data, int tex_i[3], t_point tex,
		double wall_strip_h)
{
	double	o_v[2];

	o_v[1] = data->textures[tex_i[1]]->height / wall_strip_h;
	tex_i[2] = 0;
	while (tex_i[2]++ < HEIGHT)
	{
		o_v[0] = tex_i[2] - ((HEIGHT / 2) - (wall_strip_h / 2));
		if (o_v[0] >= 0 && o_v[0] < wall_strip_h)
		{
			tex.y = fmin(o_v[0] * o_v[1], data->textures[tex_i[1]]->height - 1);
			my_put_pixel_to_image(tex_i[0] * WALL_STRIP_W, tex_i[2],
				get_pixel_img(data->textures[tex_i[1]], tex.x, tex.y));
		}
	}
}


void	render_ceiling_floor(t_data *data, double wall_strip_h, int start)
{
	if (wall_strip_h > HEIGHT)
		wall_strip_h = HEIGHT;
	fillrect((t_point){start * WALL_STRIP_W, 1}, WALL_STRIP_W, (HEIGHT
			- wall_strip_h) / 2, data->map->color_c);
	fillrect((t_point){start * WALL_STRIP_W, (HEIGHT + wall_strip_h) / 2},
		WALL_STRIP_W, (HEIGHT - wall_strip_h) / 2, data->map->color_f);
}

// Improved texture x coordinate calculation
int	set_tex_x(t_data *data, t_ray ray, int tex_i)
{
	double tex_pos;
	if (ray.was_hit_vert)
		tex_pos = fmod(ray.wall_hit.y, CUB_SIZE);
	else
		tex_pos = fmod(ray.wall_hit.x, CUB_SIZE);

	// Ensure precise mapping
	return (int)((tex_pos / CUB_SIZE) * data->textures[tex_i]->width);
}

void	render_projection_walls(t_data *data, t_ray *rays, int num_rays)
{
	double	wall_strip_h;
	double	proj_plane_dis;
	t_point	tex;
	int		i;
	int		tex_i[3];

	tex_i[1] = 0;
	i = -1;
	proj_plane_dis = (WIDTH / (double)2) / tan(degtorad(FOV) / 2);
	while (i++ < num_rays - 1)
	{
		rays[i].distance *= cos(normalize_angle(rays[i].angle
					- data->player->rot_angle));
		wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
		render_ceiling_floor(data, wall_strip_h, i);
		tex_i[1] = set_texture_index(rays, i);
		tex.x = set_tex_x(data, rays[i], tex_i[1]);
		tex_i[2] = 0;
		tex_i[0] = i;
		put_texture_color(data, tex_i, tex, wall_strip_h);
	}
}

// void	render_projection_walls(t_data *data, t_ray *rays, int num_rays)
// {
// 	double	wall_strip_h;
// 	int		i;
// 	double	proj_plane_dis;

// 	i = 0;
// 	wall_strip_h = 0;
// 	proj_plane_dis = (data->mlx.win_width / 2) / tan(degtorad(FOV) / 2);
// 	while (i < num_rays)
// 	{
// 		rays[i].distance *= cos(normalize_angle(rays[i].angle
// 					- data->player->rot_angle));
// 		wall_strip_h = (CUB_SIZE / rays[i].distance) * proj_plane_dis;
// 		if (wall_strip_h > data->mlx.win_height)
// 			wall_strip_h = data->mlx.win_height;
// 		if (rays[i].was_hit_vert)
// 			fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height / 2)
// 				- (wall_strip_h / 2)}, WALL_STRIP_W, wall_strip_h, 0x0000FF);
// 		else
// 			fillrect((t_point){i * WALL_STRIP_W, (data->mlx.win_height / 2)
// 				- (wall_strip_h / 2)}, WALL_STRIP_W, wall_strip_h, 0x00FF00);
// 		i++;
// 	}
// }
