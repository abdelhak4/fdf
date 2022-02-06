/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:15:03 by ael-mous          #+#    #+#             */
/*   Updated: 2021/12/08 12:50:34 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_strchr(char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (s[i] != 0)
	{
		if (s[i] == cc)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-2);
}

char	*print_line(char **static_ptr)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = ft_strchr(*static_ptr, '\n');
	ptr = ft_substr(*static_ptr, 0, i + 1);
	tmp = *static_ptr;
	*static_ptr = ft_substr(*static_ptr, i + 1, ft_strlen(*static_ptr));
	free(tmp);
	tmp = NULL;
	return (ptr);
}

char	*print_one_str(char **str)
{
	char	*str_tmp;

	if ((*str)[0] == '\0')
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	else
	{
		str_tmp = *str;
		*str = NULL;
	}
	return (str_tmp);
}

char	*ft_funtmp(char **t_free)
{
	free(*t_free);
	*t_free = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	ssize_t		b_fd;
	static char	*static_arr;
	char		store[BUFFER_SIZE + 1];

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (0);
	if (static_arr == NULL)
		static_arr = ft_strdup("");
	while (ft_strchr(static_arr, '\n') == -2)
	{
		b_fd = read(fd, store, BUFFER_SIZE);
		if (b_fd == -1)
			return (ft_funtmp(&static_arr));
		if (b_fd == 0)
			break ;
		store[b_fd] = '\0';
		static_arr = ft_strjoin(static_arr, store);
	}
	if (ft_strchr(static_arr, '\n') != -2)
		return (print_line(&static_arr));
	return (print_one_str(&static_arr));
}
