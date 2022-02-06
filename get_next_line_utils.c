/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:44:45 by ael-mous          #+#    #+#             */
/*   Updated: 2021/12/08 12:53:16 by ael-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		a;
	char	*sub;

	a = 0;
	if (!s)
		return (0);
	if ((len + 1) > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	if (len < 0)
		return (0);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (len > 0 && start < ft_strlen(s))
	{
		sub[a] = s[start];
		start++;
		a++;
		len--;
	}
	sub[a] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free(s1);
	return (dst);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	*(s2 + ft_strlen(s1)) = '\0';
	return (s2);
}
