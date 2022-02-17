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

void	my_mlx_pixel_put(t_list *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
	{
			dst = data->data_addr + (y * data->size_line + x
				* (data->bites_per_pixle / 8));
			*(unsigned int *) dst = color;
	}
}

t_info	cpy_infos(int x, int y, t_edge *matrix)
{
	int		z;
	t_info	list;

	z = matrix->cords[y][x];
	printf("%d\n", z);
	list.color = 0;
	if (z != 0)
		list.color = 0xFF0000;
	list.x = x;
	list.y = y;
	list.z = z;
	return (list);
}

t_info	to_iso(t_info iso)
{
	int	x;
	int	y;

	iso.scaling = 1;
	x = iso.x;
	y = iso.y;
	iso.x = x - y;
	iso.y = ((x + y) / 2) - iso.z;
//	iso.x += iso.scaling;
//	iso.y += iso.scaling;
	return (iso);
}

void	draw(t_list data, t_info from_first, t_info to_last, t_edge next_p)
{
	int		steps;
	int		dx;
	int		dy;
	float	x_inc;
	float	y_inc;
	printf("jfdkj\n");
	from_first.x += from_first.scaling;
	from_first.y += from_first.scaling;
	to_last.x += from_first.scaling;
	to_last.y += from_first.scaling;

	if (from_first.color)
		next_p.color = from_first.color;
	else if (to_last.color)
		next_p.color = to_last.color;
	else
		next_p.color = 0x0000FF;
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
	dx = 1;
	while (dx <= steps)
	{
		my_mlx_pixel_put(&data, (int)roundf(next_p.xf),
			(int)roundf(next_p.yf), next_p.color);
		next_p.xf += x_inc;
		next_p.yf += y_inc;
		dx++;
	}
}
