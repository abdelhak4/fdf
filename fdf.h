#ifndef FDF_H
#define FDF_H
#include "utils/minilibx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
# include <unistd.h>
#include <stdlib.h>
#include "utils/libft/libft.h"
#include "get_next_line.h"

typedef struct t_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		bites_per_pixle;
	int		size_line;
	int		endian;
	char	*data_addr;
}		m_list;

typedef struct t_infos
{
	int x;
	int y;
	int z;
}	s_info;

typedef struct t_Edge
{
	char	**start_M;
	int 	**cords;
	int 	**axis;
	int		height;
	int		weight;
	float	x;
	float	y;
	int 	z;
	int 	zoom;
	int 	color;
	s_info s_infos;
}		t_edge;

void	fun_to_read_store_lines(char **argv, t_edge *save_matrx);
void	draw(m_list data,s_info from_first, s_info to_last, t_edge next_p);
s_info	to_iso(s_info iso);
s_info 	cpy_inos(int x, int y);
void	my_mlx_pixel_put(m_list *data, int x, int y, int color);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

#endif