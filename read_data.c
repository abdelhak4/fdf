/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:03:26 by ael-mous          #+#    #+#             */
/*   Updated: 2022/02/13 13:04:46 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	get_rows(char **argv, t_edge *save_matrix)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDWR);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		save_matrix->rows += w_count(tmp, '\n');
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	close(fd);
}

static void	get_columns(char **argv, t_edge *save_matrix)
{
	int		fd;
	char	*tmp;

	fd = open(argv[1], O_RDWR);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		save_matrix->columns = w_count(tmp, ' ');
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
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
	get_rows(argv, save_matrix);
	get_columns(argv, save_matrix);
	save_matrix->cords = (int **)malloc(save_matrix->rows * sizeof(int *));
	fd = open(argv[1], O_RDWR);
	while (i < save_matrix->rows)
	{
		save_matrix->cords[i] = malloc(save_matrix->columns * sizeof(int));
		tmps = get_next_line(fd);
		ntmp = ft_split(tmps, ' ');
		j = 0;
		while (ntmp[j])
		{
			save_matrix->cords[i][j] = ft_atoi(ntmp[j]);
			free(ntmp[j]);
			ntmp[j] = NULL;
			j++;
		}
		free(tmps);
		tmps = NULL;
		i++;
	}
	close(fd);
}
