/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:11:57 by csouita           #+#    #+#             */
/*   Updated: 2025/03/10 22:19:52 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_valid_texture(t_map *data)
{
    if (!data->no || !data->so || !data->we || !data->ea)
    {
        ft_putstr_fd("Error\nInvalid texture\n", 2);
        free_elements(data);
        free_memory(data);
    }
}
