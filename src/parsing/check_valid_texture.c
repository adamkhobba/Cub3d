/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:34:56 by csouita           #+#    #+#             */
/*   Updated: 2025/03/14 00:37:49 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_texture(t_map *data)
{
	if (!data->no || !data->so || !data->we || !data->ea || !data->info->f
		|| !data->info->c)
	{
		ft_putstr_fd("Error\nMissing texture\n", 2);
		free_elements(data);
		free_memory(data);
	}
}
