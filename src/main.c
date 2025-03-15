/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:18:46 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/13 03:16:50y akhobba          ###   ########.fr       */
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
	data->mlx.win = mlx_new_window(data->mlx.instance, data->mlx.win_width, data->mlx.win_height, "cub3d");
	mlx_hook(data->mlx.win, DestroyNotify, StructureNotifyMask, &close_program,
		NULL);
	mlx_hook(data->mlx.win, KeyPress, KeyPressMask, update_player, NULL);
	mlx_hook(data->mlx.win, KeyRelease, KeyReleaseMask, update_player_release,
		NULL);
	mlx_mouse_hook(data->mlx.win, NULL, NULL);
}

int	main(__attribute((unused)) int ac, __attribute((unused)) char **av)
{
	t_data *data;

	if (ac != 2)
	{
		ft_putstr_fd(ERROR"\nInvalid number of arguments\n", 2);
		return (1);
	}
	data = get_data();
	// get_data()->map = parsing(ac, av);
	data->map = fake_map_init(); // tmp function
	print_map(data->map);
	data->mlx.win_height = data->map->map_height * CUB_SIZE;
	data->mlx.win_width = data->map->map_width * CUB_SIZE;
	mlx_setup_env();
	// get_data()->map = parsing(ac, av);
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		ft_putstr_fd(ERROR "\nFailed to allocate memory\n", 2);
		close_program();
	}
	player_init(data);
	_2dmap_render(data);
	mlx_loop(data->mlx.instance);
	free_map(data->map); // tmp function
	parsing(ac, av);
}
