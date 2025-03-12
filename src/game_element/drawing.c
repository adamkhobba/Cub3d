/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:54:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 15:53:48by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * @brief Fills a rectangle on the screen with a specified color.
 *
 * This function draws a filled rectangle starting from the top-left corner
 * (x, y) with the specified width and height, using the given color.
 *
 * @param x The x-coordinate of the top-left corner of the rectangle.
 * @param y The y-coordinate of the top-left corner of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 * @param color The color to fill the rectangle with.
 */
void	fillrect(int x, int y, int width, int height, int color)
{
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			my_put_pixel_to_image(j, i, color);
		}
	}
}

/**
 * fillline - Draws a line from one point to another with a specified angle and color.
 * @param from The starting point of the line.
 * @param to The ending point of the line.
 * @param angle The angle at which the line is drawn.
 * @param color The color of the line.
 *
 * This function calculates the distance between the starting and ending points,
 * then iteratively plots points along the line using the specified angle and color.
 * The final point is explicitly set to ensure the line reaches the end point.
 */
void	fillline(t_point from, t_point to, double angle, int color)
{
	double	distance;
	int		x;
	int		y;

	distance = cal_distance(from, to);
	x = from.x;
	y = from.y;
	for (int i = 0; i < distance; i++)
	{
		x += cos(angle);
		y += sin(angle);
		my_put_pixel_to_image(x, y, color);
	}
	my_put_pixel_to_image(to.x, to.y, color);
}

void draw_map(t_player	*player)
{
	t_data	*data;

	data = get_data();
	data->mlx.image.img = mlx_new_image(data->mlx.instance, WIDTH, HEIGHT);
	if (!data->mlx.image.img)
	{
		ft_putstr_fd(ERROR"\nFailed to create image\n", 2);
		close_program();
	}
	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
			&data->mlx.image.bpp, &data->mlx.image.line_len,
			&data->mlx.image.endian);
	_2dmap();
	put_player(player);
	mlx_put_image_to_window(get_data()->mlx.instance, get_data()->mlx.win,
		get_data()->mlx.image.img, 0, 0);
}