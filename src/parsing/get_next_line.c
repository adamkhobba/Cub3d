/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:52:44 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 02:32:42 by csouita          ###   ########.fr       */
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
		strncpy(buff, str, len - 1);
		free(str);
	}
	if (len == 1)
		return (free(buff), NULL);
	buff[len - 1] = 0;
	return (buff);
}
