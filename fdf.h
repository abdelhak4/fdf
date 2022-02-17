/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:18:04 by ael-mous          #+#    #+#             */
/*   Updated: 2022/02/13 13:18:06 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "utils/minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# define ESC 53

typedef struct t_Edge
{
	int		**cords;
	int		rows;
	int		columns;
	float	xf;
	float	yf;
	int		zoom;
	int		color;
}		t_edge;

typedef struct t_infos
{
	int	x;
	int	y;
	int	z;
	int	color;
	int scaling;
}	t_info;

typedef struct t_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		bites_per_pixle;
	int		size_line;
	int		endian;
	char	*data_addr;
	t_info 	info;
}		t_list;


void	fun_to_read_store_lines(char **argv, t_edge *save_matrx);
void	draw(t_list data, t_info from_first, t_info to_last, t_edge next_p);
t_info	to_iso(t_info iso);
t_info	cpy_infos(int x, int y, t_edge *matrix);
void	my_mlx_pixel_put(t_list *data, int x, int y, int color);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
