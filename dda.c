#include "fdf.h"

void	my_mlx_pixel_put(m_list *data, int x, int y, int color)
{
	char	*dst;

	if (x >=0 && x <= 800 && y >= 0 && y <= 800) {
		dst = data->data_addr + (y * data->size_line + x * (data->bites_per_pixle / 8));
		*(unsigned int *) dst = color;
	}
}

s_info	cpy_inos(int x, int y)
{
	s_info list;
	list.x = x;
	list.y = y;
	return (list);
}

s_info to_iso(s_info iso)
{
	int x;
	int y;

	x = iso.x;
	y = iso.y;
	iso.x = x - y;
	iso.y = (x + y) / 2;
	return (iso);
}

void	draw(m_list data,s_info from_first, s_info to_last, t_edge next_p)
{
	int		steps;
	int		dx;
	int		dy;
	float 	Xincrement;
	float 	Yincrement;

	from_first.x *= 30;
	to_last.x *= 30;
	from_first.y *= 30;
	to_last.y *= 30;
	dx = from_first.x - to_last.x;
	dy = from_first.y - to_last.y;
	next_p.x = (float) from_first.x;
	next_p.y = (float) from_first.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	Xincrement = dx / steps;
	Yincrement = dy / steps;
	dx = 0;
	while (dx <= steps)
	{
		my_mlx_pixel_put(&data, roundf(next_p.x) , roundf(next_p.y), 0xFFA500);
		next_p.x += Xincrement;
		next_p.y += Yincrement;
		dx++;
	}
}