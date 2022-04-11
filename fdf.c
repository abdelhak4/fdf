/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:53:44 by ael-mous          #+#    #+#             */
/*   Updated: 2022/03/01 13:49:40 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda_draw(t_list *data, t_edge *save_matrix)
{
	int	x_n;
	int	y_n;

	y_n = 0;
	while (y_n < save_matrix->rows)
	{
		x_n = 0;
		while (x_n < save_matrix->columns)
		{
			if (x_n < save_matrix->columns - 1)
				draw(*data, to_iso(cpy_infos(x_n, y_n, save_matrix)),
					to_iso(cpy_infos(x_n + 1, y_n, save_matrix)), *save_matrix);
			if (y_n < save_matrix->rows - 1)
				draw(*data, to_iso(cpy_infos(x_n, y_n, save_matrix)),
					to_iso(cpy_infos(x_n, y_n + 1, save_matrix)), *save_matrix);
			x_n++;
		}
		y_n++;
	}
}

int	destroy(int keyPres)
{
	if (keyPres == ESC)
		exit(0);
	return (0);
}

int	close_frame(void)
{
	exit(0);
}

void	draw_fun(t_list *data, t_edge *save_matrix)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 2000, 1200, "fdf window");
	data->img = mlx_new_image(data->mlx_ptr, 2000, 1200);
	data->data_addr = mlx_get_data_addr(data->img, &data->bites_per_pixle,
			&data->size_line, &data->endian);
	mlx_key_hook(data->mlx_win, destroy, data);
	dda_draw(data, save_matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 17, 0, close_frame, NULL);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_edge	save_matrix;
	t_list	data;

	if (argc < 2)
	{
		perror("Error ");
		write(1, "Please enter a map path\n", 24);
		return (-1);
	}
	ft_check_ext(argc, argv);
	save_matrix.zoom = 4;
	save_matrix.rows = 0;
	save_matrix.columns = 0;
	fun_to_read_store_lines(argv, &save_matrix);
	draw_fun(&data, &save_matrix);
	return (0);
}
