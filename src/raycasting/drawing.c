/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:54:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 04:40:02 by akhobba          ###   ########.fr       */
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
{
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			mlx_put_pixel_to_image(j, i, color);
		}
	}
}
/**
 * @brief Draws a line from (x_form, y_form) to (x_to, y_to) with the specified color.
 *
 * This function uses the DDA (Digital Differential Analyzer) algorithm to draw a line
 * between two points on the screen. It calculates the necessary increments for the x and y
 * coordinates and iteratively plots the points using the mlx_put_pixel_to_image function.
 *
 * @param x_form The starting x-coordinate of the line.
 * @param y_form The starting y-coordinate of the line.
 * @param x_to The ending x-coordinate of the line.
 * @param y_to The ending y-coordinate of the line.
 * @param color The color of the line to be drawn.
 */
void	fillline(int x_form, int y_form, int x_to, int y_to , int color)
{
	// TODO: understand this function
	int dx = x_to - x_form;
	int dy = y_to - y_form;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	double x_inc = dx / (double)steps;
	double y_inc = dy / (double)steps;
	double x = x_form;
	double y = y_form;
	for(int i = 0; i <= steps; i++)
	{
		mlx_put_pixel_to_image(x, y, color);
		x += x_inc;
		y += y_inc;
	}
}

void draw_map(void)
{
	_2dmap();
	player_init(&get_data()->player);
	put_player(&get_data()->player);
}