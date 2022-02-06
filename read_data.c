#include "fdf.h"

static int	w_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static void get_height(char **argv, t_edge *save_matrix)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDWR);
	while ((tmp = get_next_line(fd)) != NULL)
		save_matrix->height += w_count(tmp, '\n');
	free(tmp);
	tmp = NULL;
	close(fd);
}

static	void get_weight(char **argv, t_edge *save_matrix)
{
	int 	fd;
	char	*tmp;

	fd = open(argv[1], O_RDWR);
	while ((tmp = get_next_line(fd)) != NULL)
		save_matrix->weight = w_count(tmp, ' ');
	free(tmp);
	tmp = NULL;
	close(fd);
}

void	fun_to_read_store_lines(char **argv, t_edge *save_matrix)
{
	int		i;
	int		j;
	int		fd;
	char	**ntmp;
	char	*tmps;

	i = 0;
	j = 0;
	get_height(argv, save_matrix);
	get_weight(argv, save_matrix);
	save_matrix->cords = (int **)malloc(save_matrix->height * sizeof(int**));
	fd = open(argv[1], O_RDWR);
	while (i < save_matrix->height)
	{
		save_matrix->cords[i] = malloc(save_matrix->weight * sizeof(int *));
		tmps = get_next_line(fd);
		ntmp = ft_split(tmps, ' ');
		while (ntmp[j])
		{
			save_matrix->cords[i][j] = ft_atoi(ntmp[j]);
			free(ntmp[j]);
			ntmp[j] = NULL;
			j++;
		}
		free(tmps);
		tmps = NULL;
		j = 0;
		i++;
	}
	close(fd);
}