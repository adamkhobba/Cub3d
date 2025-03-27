/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:01:09 by csouita           #+#    #+#             */
/*   Updated: 2025/03/26 02:36:15 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_void(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	handle_quotes3(char *str, int *i, char quote_char)
{
	(*i)++;
	while (str[*i] && str[*i] != quote_char)
		(*i)++;
	if (str[*i] && str[*i] == quote_char)
		(*i)++;
	return (1);
}

char	**freefun00(char **p, int j)
{
	while (j >= 0)
	{
		free(p[j]);
		j--;
	}
	free(p);
	return (NULL);
}
