/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:53:19 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/04 13:39:17 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	int		len;
	int		i;
	char	*ptr;

	len = count * size;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

char	*ft_gnl_strjoin(char *s, char *buf)
{
	int		i;
	int		j;
	char	*join;

	if (!s || !buf)
		return (NULL);
	join = (char *)ft_gnl_calloc(sizeof(char),
			ft_gnl_strlen(s) + ft_gnl_strlen(buf) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s[i])
	{
		join[i] = s[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		join[i + j] = buf[j];
		j++;
	}
	free(s);
	return (join);
}
