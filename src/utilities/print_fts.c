/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 03:07:08 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/14 04:55:40 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *data)
{
	int	i;

	i = 0;
	printf("map height: %d\n", data->map_height);
	printf("map width: %d\n", data->map_width);
	while (i < data->map_height)
	{
		printf("%s", data->map[i]);
		printf("\n");
		i++;
	}
	printf("printing is done\n");
}
