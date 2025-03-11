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
void fillrect(int x, int y, int width, int height, int color)
{
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			my_put_pixel_to_image(j, i, color);
		}
	}
}

void	fillline(int x_from, int y_from, int x_to, int y_to , int color)
{
	int		dx;
	int		dy;
	int		steps;
	double	x_inc;
	double	y_inc;

	dx = x_to - x_from;
	dy = y_to - y_from;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	for(int i = 0; i <= steps; i++)
	{
		my_put_pixel_to_image(x_from, y_from, color);
		x_from += x_inc;
		y_from += y_inc;
	}
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