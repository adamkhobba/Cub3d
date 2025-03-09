/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:18:46 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/09 23:20:39 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_data	*g_data(void)
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

	data = g_data();
	data->mlx.win = mlx_new_window(data->mlx.instance, WIDTH, HEIGHT, "miniRT");
	data->mlx.image.img = mlx_new_image(data->mlx.instance, WIDTH, HEIGHT);
	data->mlx.image.addr = mlx_get_data_addr(data->mlx.image.img,
			&data->mlx.image.bpp, &data->mlx.image.line_len,
			&data->mlx.image.endian);
	mlx_hook(g_data()->mlx.win, DestroyNotify, StructureNotifyMask, ft_close,
		NULL);
	mlx_hook(g_data()->mlx.win, KeyPress, KeyPressMask, key_press_hook, NULL);
	mlx_hook(g_data()->mlx.win, KeyRelease, KeyReleaseMask, key_release_hook,
		NULL);
	mlx_mouse_hook(g_data()->mlx.win, mouse_hook, NULL);
}

int main (int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}




}