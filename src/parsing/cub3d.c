/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/03/11 02:32:46 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

char	**init_split_memory(t_map *data)
{
	char	**split;

	split = malloc(sizeof(char *) * (data->height + 1));
	if (!split)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free_memory(data);
	}
	return (split);
}

void	cp_map_array(t_map *data, char *av[])
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free_memory(data);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	check_invalid_character(data);
	close(fd);
}

int	free_memory(t_map *data)
{
	int	k;

	k = 0;
	while (k < data->height)
	{
		free(data->map[k]);
		k++;
	}
	free(data->map);
	free(data);
	exit(1);
}

