/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:06:09 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/13 16:36:46 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_program(void)
{
	mlx_destroy_image(get_data()->mlx.instance, get_data()->mlx.image.img);
	printf("Exiting the program\n");
	mlx_destroy_window(get_data()->mlx.instance, get_data()->mlx.win);
	mlx_destroy_display(get_data()->mlx.instance);
	free(get_data()->player);
	free(get_data()->mlx.instance);
	exit(0);
	return (0);
}
