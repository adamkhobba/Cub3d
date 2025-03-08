/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:07:48 by csouita           #+#    #+#             */
/*   Updated: 2025/03/04 01:20:23 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	words_nbr00(char *str)
{
	int	i;
	int	words_count;
	int	start;

	i = 0;
	words_count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_void(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_is_void(str[i]))
		{
			if (str[i] && (str[i] == '\'' || str[i] == '"'))
				handle_quotes3(str, &i, str[i]);
			else
				i++;
		}
		if (start != i)
			words_count++;
		if (str[i] == '\0')
			return (words_count);
		i++;
	}
	return (words_count);
}

static char	*malloc_word00(char *s, int begin, int end)
{
	int		i;
	char	*str;

	str = (char *)malloc((end - begin + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (begin < end)
	{
		str[i] = s[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}

int	while_loop(char *s, int i, char c)
{
	while (s[i] && !ft_is_void(s[i]))
	{
		if (s[i] && (s[i] == '\'' || s[i] == '"'))
		{
			c = s[i];
			i++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (i);
}

static char	**list00(char **lst, char *s)
{
	char	c;
	int		i;
	int		j;
	int		start;

	c = 0;
	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (!ft_is_void(s[i]))
		{
			start = i;
			i = while_loop(s, i, c);
			lst[j] = malloc_word00(s, start, i);
			if (!lst[j])
				return (freefun00(lst, j));
			j++;
		}
		else
			i++;
	}
	lst[j] = NULL;
	return (lst);
}

char	**ft_split00(char *s)
{
	char	**lst;

	if (!s)
		return (NULL);
	lst = (char **)malloc((words_nbr00(s) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	return (list00(lst, s));
}
