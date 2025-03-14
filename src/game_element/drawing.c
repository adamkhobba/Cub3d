/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:54:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 00:37:28 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Fills a rectangle on the screen with a specified color.
 *
 * This function draws a filled rectangle starting from the given point
 * (top-left corner) with the specified width and height, using the provided
 * color.
 *
 * @param point The top-left corner of the rectangle to be filled.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 * @param color The color to fill the rectangle with.
 */

void	fillrect(t_point point, int width, int height, int color)
{
	int	j;
	int	i;

	i = point.y;
	while (i < point.y + height)
	{
		j = point.x;
		while (j < point.x + width)
		{
			my_put_pixel_to_image(j, i, color);
			j++;
		}
		i++;
	}
}

/**
 * fillline
	- Draws a line from one point to another with a specified angle and color.
 * @param from The starting point of the line.
 * @param to The ending point of the line.
 * @param angle The angle at which the line is drawn.
 * @param color The color of the line.
 *
 * This function calculates the distance between the starting and ending points,

 * then iteratively plots points along the line using the specified angle and
 color.
 * The final point is explicitly set to ensure the line reaches the end point.
 */
void	fillline(t_point from, t_point to, double angle, int color)
{
	double	distance;
	double	x;
	double	y;
	double	step;

	distance = cal_distance(from, to);
	step = 1;
	x = from.x;
	y = from.y;
	while (step < distance)
	{
		x = from.x + cos(angle) * step;
		y = from.y + sin(angle) * step;
		my_put_pixel_to_image(x, y, color);
		step++;
	}
	my_put_pixel_to_image(to.x, to.y, color);
}

void	_2dmap(t_map *map)
{
	t_point	point;
	int		i;
	int		j;

	i = 0;
	while (i < map->info->height)
	{
		j = 0;
		while (j < map->map_width)
		{
			point = (t_point){j * CUB_SIZE, i * CUB_SIZE};
			if (map->map[i][j] == 1)
				fillrect(point, CUB_SIZE - 1, CUB_SIZE - 1, 0x222222);
			else
				fillrect(point, CUB_SIZE - 1, CUB_SIZE - 1, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_2dmap(t_data *data)
{
	data->mlx.image.img = mlx_new_image(data->mlx.instance, WIDTH, HEIGHT);
	if (!data->mlx.image.img)
	{
		ft_putstr_fd(ERROR "\nFailed to create image\n", 2);
		close_program();
	}
	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
			&data->mlx.image.bpp, &data->mlx.image.line_len,
			&data->mlx.image.endian);
	_2dmap(data->map);
	put_player(data->player);
	mlx_put_image_to_window(get_data()->mlx.instance, get_data()->mlx.win,
		get_data()->mlx.image.img, 0, 0);
}
