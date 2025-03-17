/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_need.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:49:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/17 00:37:27 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


t_map	*fake_map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd(ERROR "\nFailed to allocate memory\n", 2);
		close_program();
	}
	map->map_height = 7;
	map->map_width = 14;
	map->kharita = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->kharita)
	{
		ft_putstr_fd(ERROR "\nFailed to allocate memory\n", 2);
		close_program();
	}
	map->kharita[0] = ft_strdup("11111111111111");
	map->kharita[1] = ft_strdup("10010000000001");
	map->kharita[2] = ft_strdup("10010000000111");
	map->kharita[3] = ft_strdup("10000001000001");
	map->kharita[4] = ft_strdup("10000100000001");
	map->kharita[5] = ft_strdup("10000100000001");
	map->kharita[6] = ft_strdup("11111111111111");
	map->kharita[7] = NULL;
	map->player_x = 6;
	map->player_y = 2;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		free(map->kharita[i]);
		i++;
	}
	free(map->kharita);
	free(map);
}