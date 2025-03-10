/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:11:30 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/10 03:30:22 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degtorad(double deg)
{
	return (deg * ((double)M_PI / (double)180));
}

double	radtodeg(double rad)
{
	return (rad * ((double)180 / (double)M_PI));
}