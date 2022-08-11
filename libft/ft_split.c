/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:21:28 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/07/01 15:29:13 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_row_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

static char	**make_array(char const *s, char c, char **split, int row)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0' && split[row] != NULL)
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != '\0' && s[i + j] != c)
				j++;
			split[row] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[row] == NULL)
			{
				free_split(split);
				return (NULL);
			}
			ft_strlcpy(split[row++], s + i, j + 1);
			i = i + j;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		row;
	char	**split;

	if (s == NULL)
		return (NULL);
	row = get_row_count(s, c);
	split = (char **)malloc(sizeof(char *) * (row + 1));
	if (split == NULL)
		return (NULL);
	split[row] = NULL;
	while (row > 0)
	{
		split[row - 1] = "";
		row--;
	}
	split = make_array(s, c, split, row);
	return (split);
}
