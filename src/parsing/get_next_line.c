/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:52:44 by csouita           #+#    #+#             */
/*   Updated: 2025/03/27 00:21:28 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	int		len;
	char	*buff;
	char	*str;

	len = 1;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff || read(fd, buff, 0) == -1)
		return (free(buff), NULL);
	while (read(fd, buff + len - 1, 1) && buff[len++ - 1] != '\n')
	{
		str = buff;
		buff = malloc(sizeof(char) * (len + 1));
		if (!buff)
			return (free(str), NULL);
		ft_strncpy(buff, str, len - 1);
		free(str);
	}
	if (len == 1)
		return (free(buff), NULL);
	buff[len - 1] = 0;
	return (buff);
}
