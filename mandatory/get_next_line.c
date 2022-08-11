/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:54:03 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/04 13:39:45 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_join(int fd, char *s);
int		is_new_line(char *s);
char	*get_result_line(char *s);
char	*get_new_static(char *s);

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	temp = s;
	s = read_and_join(fd, s);
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	line = get_result_line(s);
	s = get_new_static(s);
	return (line);
}

char	*read_and_join(int fd, char *s)
{
	int		rbyte;
	char	*buf;

	if (!s)
		s = (char *)ft_gnl_calloc(sizeof(char), 1);
	if (!s)
		return (NULL);
	buf = (char *)ft_gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rbyte = 1;
	while (rbyte > 0 && is_new_line(s) < 0)
	{
		rbyte = read(fd, buf, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rbyte] = '\0';
		s = ft_gnl_strjoin(s, buf);
	}
	free (buf);
	return (s);
}

int	is_new_line(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_result_line(char *s)
{
	int		i;
	int		index;
	char	*result;

	if (!s[0])
		return (NULL);
	index = 0;
	while (s[index] && s[index] != '\n')
		index++;
	result = (char *)ft_gnl_calloc(sizeof(char), index + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i < index)
	{
		result[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		result[i] = s[i];
	return (result);
}

char	*get_new_static(char *s)
{
	int		i;
	int		index;
	char	*new;

	index = 0;
	while (s[index] && s[index] != '\n')
		index++;
	if (!s[index])
	{
		free(s);
		return (NULL);
	}
	new = (char *)ft_gnl_calloc(sizeof(char), ft_gnl_strlen(s) - index + 1);
	if (!new)
		return (NULL);
	index++;
	i = 0;
	while (s[index])
		new[i++] = s[index++];
	free(s);
	return (new);
}
