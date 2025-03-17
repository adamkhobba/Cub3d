/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:07:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/17 00:37:27 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *data)
{
	int	i;

	i = 0;
	printf("map height: %d\n", data->map_height);
	printf("map width: %d\n", data->map_width);
	printf("map->player_x: %d\n", data->player_x);
	printf("map->player_y: %d\n", data->player_y);
	while (i < data->map_height)
	{
		printf("%s", data->kharita[i]);
		i++;
	}
	printf("printing is done\n");
}
