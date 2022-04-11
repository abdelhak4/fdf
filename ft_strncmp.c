/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:17:46 by ael-mous          #+#    #+#             */
/*   Updated: 2022/02/20 15:17:50 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_ext(int ac, char **av)
{
	int	i;
	int	c;

	i = ft_strlen(av[ac - 1]) - 1;
	c = ft_strncmp(&av[1][i - 3], ".fdf", 4);
	if (c != 0)
	{
		write(1, "not a valide extension\n", 24);
		exit(-1);
	}
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] || ss2[i]) && i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (i != n)
		return (ss1[i] - ss2[i]);
	return (0);
}
