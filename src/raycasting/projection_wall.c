/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:46:40 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/27 04:19:35 by akhobba          ###   ########.fr       */
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

int	set_tex_x(t_data *data, t_ray ray, int tex_i)
{
	if (ray.was_hit_vert)
		return (fmod(ray.wall_hit.y, CUB_SIZE) * data->textures[tex_i]->width
			/ CUB_SIZE);
	else
		return (fmod(ray.wall_hit.x, CUB_SIZE) * data->textures[tex_i]->width
			/ CUB_SIZE);
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

void	render_projection_walls(t_data *data, t_ray *rays, int num_rays)
{
	double	wall_strip_h;
	double	proj_plane_dis;
	t_point	tex;
	int		tex_i[3];

	tex_i[0] = 0;
	tex_i[1] = 0;
	proj_plane_dis = (WIDTH / (double)2) / tan(degtorad(FOV) / 2);
	while (tex_i[0]++ < num_rays - 2)
	{
		rays[tex_i[0]].distance *= cos(normalize_angle(rays[tex_i[0]].angle
					- data->player->rot_angle));
		wall_strip_h = (CUB_SIZE / rays[tex_i[0]].distance) * proj_plane_dis;
		render_ceiling_floor(data, wall_strip_h, tex_i[0]);
		tex_i[1] = set_texture_index(rays, tex_i[0]);
		tex.x = set_tex_x(data, rays[tex_i[0]], tex_i[1]);
		tex_i[2] = 0;
		put_texture_color(data, tex_i, tex, wall_strip_h);
	}
}
