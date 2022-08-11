/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:53:42 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/04 13:31:41 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *s);
int		is_new_line(char *s);
char	*get_result_line(char *s);
char	*get_new_static(char *s);

size_t	ft_gnl_strlen(char *str);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*ft_gnl_strjoin(char *s, char *buf);

#endif
