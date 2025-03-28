/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 01:06:40 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 23:41:14 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || filename[len - 1] != 'm' || filename[len - 2] != 'p'
		|| filename[len - 3] != 'x' || filename[len - 4] != '.')
	{
		return (0);
	}
	return (1);
}

int	check_xpm(t_map *data)
{
	if (!check_xpm_extension(data->no))
	{
		ft_error("Error\nInvalid file extension for North texture\n", data);
		exit(1);
	}
	if (!check_xpm_extension(data->so))
	{
		ft_error("Error\nInvalid file extension for South texture\n", data);
		exit(1);
	}
	if (!check_xpm_extension(data->we))
	{
		ft_error("Error\nInvalid file extension for West texture\n", data);
		exit(1);
	}
	if (!check_xpm_extension(data->ea))
	{
		ft_error("Error\nInvalid file extension for East texture\n", data);
		exit(1);
	}
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
		free_elements(data);
		free_2d(data->kharita);
		free(data->info);
		free(data);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nInvalid file path\n", data);
}
