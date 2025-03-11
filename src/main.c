/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:18:46 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 02:39:34 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*g_data(void)
{
	static t_data	data;

	return (&data);
}


/**
 * Initialize the mlx instance
 * @return void
*/
// void	mlx_setup_env(void)
// {
// 	t_data	*data;

// 	data = g_data();
// 	data->mlx.win = mlx_new_window(data->mlx.instance, WIDTH, HEIGHT, "miniRT");
// 	data->mlx.image.img = mlx_new_image(data->mlx.instance, WIDTH, HEIGHT);
// 	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
// 			&data->mlx.image.bpp, &data->mlx.image.line_len,
// 			&data->mlx.image.endian);
// 	mlx_hook(g_data()->mlx.win, DestroyNotify, StructureNotifyMask, ft_close,
// 		NULL);
// 	mlx_hook(g_data()->mlx.win, KeyPress, KeyPressMask, key_press_hook, NULL);
// 	mlx_hook(g_data()->mlx.win, KeyRelease, KeyReleaseMask, key_release_hook,
// 		NULL);
// 	mlx_mouse_hook(g_data()->mlx.win, mouse_hook, NULL);
// }

int	main(int ac, char *av[])
{
	t_map	*data;

	data = malloc(sizeof(t_map));
	ft_memset(data, 0, sizeof(t_map));
	ft_check_file_path(data, ac, av);
	last_line(data);
	parse_textures(data);
	if (check_xpm(data))
	{
		free_elements(data);
		free_memory(data);
	}
	first_line_in_map(data);
	if (first_and_last_lines_check(data))
		free_memory(data);
	check_player_valid_pos(data);
	printf("playable\n");
	free_memory(data);
	return (0);
}