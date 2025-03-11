/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:21:29 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 02:31:44 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void setup(void)
{

}

void update(void)
{

}

void draw(void)
{
	update();
}

void fillrect(int x, int y, int width, int height, int color)
{
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			mlx_put_pixel_to_image(y, x, color);
		}
	}
}

void test_1(void)
{
	printf("Hello World\n");
	double cub_size = 64;
	// double fov = 120;
	double map_rows = 11;
	double map_coloms = 15;
	// double wwidth = map_coloms * cub_size;
	// double wheight = map_rows * cub_size;
	int map[11][15] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for(int i = 0; i < map_rows; i++)
	{
		for(int j = 0; j < map_coloms; j++)
		{
			if(map[i][j] == 1)
				fillrect(j * cub_size, i * cub_size, cub_size, cub_size, 0x000000);
			else
				fillrect(j * cub_size, i * cub_size, cub_size, cub_size, 0xFFFFFF);
		}
	}
}