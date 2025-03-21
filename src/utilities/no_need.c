/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_need.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:49:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/21 01:39:15 by akhobba          ###   ########.fr       */
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
	map->map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map)
	{
		ft_putstr_fd(ERROR "\nFailed to allocate memory\n", 2);
		close_program();
	}
	map->map[0] = ft_strdup("11111111111111");
	map->map[1] = ft_strdup("10010000000001");
	map->map[2] = ft_strdup("10010000000111");
	map->map[3] = ft_strdup("10000001000001");
	map->map[4] = ft_strdup("10000100000001");
	map->map[5] = ft_strdup("10000100000001");
	map->map[6] = ft_strdup("11111111111111");
	map->map[7] = NULL;
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
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
