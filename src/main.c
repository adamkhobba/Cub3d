/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:18:46 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 00:39:39 by csouita          ###   ########.fr       */
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
		ft_putstr_fd(ERROR "\nFailed to create image\n", 2);
		close_program();
	}
	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
			&data->mlx.image.bpp, &data->mlx.image.line_len,
			&data->mlx.image.endian);
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &close_program,
		NULL);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, update_player, NULL);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, update_player_release,
		NULL);
	mlx_mouse_hook(data->mlx.win, NULL, NULL);
}
// TODO: create a fts that convert from deg to radian

int	main(__attribute((unused)) int ac, __attribute((unused)) char **av)
{
	// if (ac != 2)
	// {
	// 	ft_putstr_fd(ERROR"\nInvalid number of arguments\n", 2);
	// 	return (1);
	// }
	// mlx_setup_env();
	// get_data()->player = malloc(sizeof(t_player));
	// if (!get_data()->player)
	// {
	// 	ft_putstr_fd(ERROR "\nFailed to allocate memory\n", 2);
	// 	close_program();
	// }
	// draw_2dmap(get_data());
	// mlx_loop(get_data()->mlx.instance);
	parsing(ac, av);
}
