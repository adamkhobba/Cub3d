/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:07:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/27 01:01:52 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_print(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
	{
		printf("map is NULL\n");
		return ;
	}
	printf("map height: %d\n", map->map_height);
	printf("map width: %d\n", map->map_width);
	printf("map->player_x: %d\n", map->player_x);
	printf("map->player_y: %d\n", map->player_y);
	while (i < map->map_height)
	{
		printf("|%s|", map->null_map[i]);
		i++;
	}
	printf("printing is done !\n");
}
