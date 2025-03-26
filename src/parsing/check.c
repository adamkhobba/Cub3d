/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:06:40 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 23:45:48 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm(t_map *data)
{
	int	len;

	len = ft_strlen(data->no);
	if (data->no[len - 1] != 'm' || data->no[len - 2] != 'p' || data->no[len
			- 3] != 'x' || data->no[len - 4] != '.')
		ft_error("Error\nInvalid file extension1\n", data);
	len = ft_strlen(data->so);
	if (data->so[len - 1] != 'm' || data->so[len - 2] != 'p' || data->so[len
			- 3] != 'x' || data->so[len - 4] != '.')
		ft_error("Error\nInvalid file extension1\n", data);
	len = ft_strlen(data->we);
	if (data->we[len - 1] != 'm' || data->we[len - 2] != 'p' || data->we[len
			- 3] != 'x' || data->we[len - 4] != '.')
		ft_error("Error\nInvalid file extension1\n", data);
	len = ft_strlen(data->ea);
	if (data->ea[len - 1] != 'm' || data->ea[len - 2] != 'p' || data->ea[len
			- 3] != 'x' || data->ea[len - 4] != '.')
		ft_error("Error\nInvalid file extension1\n", data);
	return (0);
}

int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		i++;
	return (i);
}

void	ft_check_file_path(t_map *data, int ac, char *av[])
{
	int	fd;
	int	len;

	if (!data)
		ft_error("Error\nMemory allocation failed\n", data);
	if (ac != 2)
		ft_error("Error\nInvalid number of arguments\n", data);
	data->info->file = av[1];
	len = ft_strlen(av[1]);
	if (len < 4 || av[1][len - 1] != 'b' || av[1][len - 2] != 'u' || av[1][len
		- 3] != 'c' || av[1][len - 4] != '.')
		{
			ft_putstr_fd("Error\nInvalid file extension\n", 2);
			free_memory(data);
			exit(1);
		}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nInvalid file path\n", data);
}
