/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:10:04 by ael-mous          #+#    #+#             */
/*   Updated: 2022/02/13 13:17:12 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	cpy_infos(int x, int y, t_edge *matrix)
{
	int		z;
	t_info	list;

	z = matrix->cords[y][x];
	list.color = 0;
	if (z != 0)
		list.color = 0xFF0000;
	list.x = x * matrix->zoom;
	list.y = y * matrix->zoom;
	list.z = z;
	return (list);
}

t_info	to_iso(t_info iso)
{
	int	x;
	int	y;

	iso.scaling = 100;
	x = iso.x;
	y = iso.y;
	iso.x = x - y;
	iso.y = ((x + y) / 2) - iso.z;
	iso.x += iso.scaling;
	iso.y += iso.scaling;
	return (iso);
}

int	ft_color(t_info from_first, t_info to_last)
{
	int	color;

	if (from_first.color)
		color = from_first.color;
	else if (to_last.color)
		color = to_last.color;
	else
		color = 0x0000FF;
	return (color);
}

void	draw(t_list data, t_info from_first, t_info to_last, t_edge next_p)
{
	int		steps;
	int		dx;
	int		dy;
	float	x_inc;
	float	y_inc;

	next_p.color = ft_color(from_first, to_last);
	dx = to_last.x - from_first.x;
	dy = to_last.y - from_first.y;
	next_p.xf = (float) from_first.x;
	next_p.yf = (float) from_first.y ;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_inc = (float)dx / (float)steps;
	y_inc = (float)dy / (float)steps;
	dx = -1;
	while (++dx <= steps)
	{
		my_mlx_pixel_put(&data, (int)roundf(next_p.xf),
			(int)roundf(next_p.yf), next_p.color);
		next_p.xf += x_inc;
		next_p.yf += y_inc;
	}
}
