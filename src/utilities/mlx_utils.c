/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:12:23 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/11 17:46:32 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Put a pixel to the image
 * @param x: the x coordinate of the pixel
 * @param y: the y coordinate of the pixel
 * @param color: the color of the pixel
 * @return void
 */
void	my_put_pixel_to_image(int x, int y, int color)
{
	int	offset;

	offset = (y * get_data()->mlx.image.line_len + x
			* (get_data()->mlx.image.bpp / 8));
	*(unsigned int *)(get_data()->mlx.image.addr + offset) = color;
}
