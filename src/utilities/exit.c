/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:06:09 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/27 00:17:50 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_img **textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(get_data()->mlx.instance, textures[i]->img);
		free(textures[i]);
		i++;
	}
}

int	close_program(void)
{
	free_textures(get_data()->textures);
	free(get_data()->player);
	free_elements(get_data()->map);
	free_memory(get_data()->map);
	mlx_destroy_image(get_data()->mlx.instance, get_data()->mlx.image.img);
	mlx_destroy_window(get_data()->mlx.instance, get_data()->mlx.win);
	mlx_destroy_display(get_data()->mlx.instance);
	free(get_data()->mlx.instance);
	exit(0);
	return (0);
}
