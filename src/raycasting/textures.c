/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:57:48 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/25 23:30:49 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_img(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y * data->line_len + x
			* (data->bpp / 8))));
}


t_img *initialize_text(t_data *data, char *path)
{
    t_img *text = malloc(sizeof(t_img));
    text->img = mlx_xpm_file_to_image(data->mlx.instance, path, &text->width, &text->height);
    if (!text->img)
    {
        ft_putstr_fd("Error\nTexture not found\n", 2);
        exit(1);
    }
    text->addr = mlx_get_data_addr(text->img ,&text->bpp , &text->line_len, &text->endian);
    if (!text->addr)
    {
        ft_putstr_fd("Error\nTexture not found2\n", 2);
        exit(1);
    }
    return text;
}

void init_text(t_data *data)
{
    data->textures[0] = initialize_text(data, data->map->no);
    data->textures[1] = initialize_text(data, data->map->so);
    data->textures[2] = initialize_text(data, data->map->we);
    data->textures[3] = initialize_text(data, data->map->ea);
}