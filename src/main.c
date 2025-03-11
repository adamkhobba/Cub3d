/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:18:46 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 02:27:11 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}


/**
 * Initialize the mlx instance
 * @return void
*/
void	mlx_setup_env(void)
{
	t_data	*data;

	data = get_data();
	data->mlx.instance = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.instance, WIDTH, HEIGHT, "cub3d");
	data->mlx.image.img = mlx_new_image(data->mlx.instance, WIDTH, HEIGHT);
	if (!data->mlx.image.img)
	{
		ft_putstr_fd(ERROR"\nFailed to create image\n", 2);
		close_program();
	}
	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
			&data->mlx.image.bpp, &data->mlx.image.line_len,
			&data->mlx.image.endian);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &close_program,
		NULL);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, NULL, NULL);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, NULL,
		NULL);
	mlx_mouse_hook(data->mlx.win, NULL, NULL);
}
// TODO: create a fts that convert from deg to radian

void fillrect(int x, int y, int width, int height, int color)
{
	printf("x: %d, y: %d, width: %d, height: %d, color: %d\n", x, y, width, height, color);
	for(int i = y; i < y + height; i++)
	{
		for(int j = x; j < x + width; j++)
		{
			mlx_put_pixel_to_image(j, i, color);
		}
	}
}

int main (__attribute((unused)) int ac,__attribute((unused)) char **av)
{
	// if (ac != 2)
	// {
	// 	ft_putstr_fd(ERROR"\nInvalid number of arguments\n", 2);
	// 	return (1);
	// }
	mlx_setup_env();
	get_data()->mlx.image.img = NULL;
	double cub_size = 32;
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
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
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
	mlx_put_image_to_window(get_data()->mlx.instance, get_data()->mlx.win,
		get_data()->mlx.image.img, 0, 0);
	mlx_loop(get_data()->mlx.instance);
	// reading the map
}