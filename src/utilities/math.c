/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:11:30 by akhobba           #+#    #+#             */
/*   Updated: 2025/03/17 00:52:56 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	cal_distance(t_point point1, t_point point2)
{
	return (sqrtf(pow(point2.x - point1.x, 2) + pow(point2.y
				- point1.y, 2)));
}

double	degtorad(double deg)
{
	return (deg * ((double)M_PI / (double)180));
}

double	radtodeg(double rad)
{
	return (rad * ((double)180 / (double)M_PI));
}
