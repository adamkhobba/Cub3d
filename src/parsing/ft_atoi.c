/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:54:07 by csouita           #+#    #+#             */
/*   Updated: 2025/03/04 01:19:35 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long (i), (sig), (res);
	res = 0;
	i = 0;
	sig = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		res = res * 10 + str[i++] - '0';
	if (res * sig > 255 || res * sig < 0)
		return (-1);
	if (str[i])
		return (-1);
	return (sig * res);
}
