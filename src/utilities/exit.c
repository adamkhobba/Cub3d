/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:06:09 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 00:51:43 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_program(void)
{
	mlx_destroy_image(get_data()->mlx.instance, get_data()->mlx.image.img);
	mlx_destroy_window(get_data()->mlx.instance, get_data()->mlx.win);
	mlx_destroy_display(get_data()->mlx.instance);
	free(get_data()->mlx.instance);
	free_elements(get_data()->map);
	free_memory(get_data()->map);	
	exit(0);
	return (0);
}
