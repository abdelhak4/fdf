#include "fdf.h"

void	bres_draw(m_list *data, t_edge *save_matrix)
{
	int	x_n;
	int	y_n;

	y_n = 0;
	while (y_n  < save_matrix->height)
	{
		x_n = 0;
		while (x_n < save_matrix->weight)
		{
			save_matrix->z = save_matrix->cords[y_n][x_n];
			if (x_n < save_matrix->weight - 1)
				draw(*data, to_iso(cpy_inos(x_n, y_n)), 
					 to_iso(cpy_inos(x_n+1, y_n)), *save_matrix);
			if (y_n < save_matrix->height - 1)
				draw(*data, to_iso(cpy_inos(x_n, y_n)), 
					 to_iso(cpy_inos(x_n, y_n+1)), *save_matrix);
			x_n++;
		}
		y_n++;
	}
}

void	draw_fun(m_list *data, t_edge *save_matrix)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf image");
	data->img = mlx_new_image(data->mlx_ptr, 800, 800);
	data->data_addr = mlx_get_data_addr(data->img, &data->bites_per_pixle,
										&data->size_line, &data->endian);
	bres_draw(data, save_matrix);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 20, 20);
	mlx_loop(data->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_edge save_matrix;
	m_list data;
	int i = 0;
	int j;
	if (argc < 2)
	{
		perror("Error ");
		write(1, "Please enter a map path\n", 24);
		return (-1);
	}
	save_matrix.zoom = 20;
	save_matrix.height = 0;
	save_matrix.weight = 0;
	fun_to_read_store_lines(argv, &save_matrix);
	draw_fun(&data, &save_matrix);
	return (0);
}