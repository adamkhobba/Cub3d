/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:20:01 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 23:51:08 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_(t_map *data)
{
	free_elements(data);
	free_2d(data->kharita);
	free(data->info);
	free(data);
}

void	free_memory(t_map *map)
{
	free(map->info);
	free_2d(map->kharita);
	free_2d(map->null_map);
	free_2d(map->map);
	free(map);
}
