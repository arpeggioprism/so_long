/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:25:55 by jshin             #+#    #+#             */
/*   Updated: 2022/02/05 17:52:06 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*dest && count < size)
	{
		dest++;
		count++;
	}
	while (count + 1 < size && *src)
	{
		*dest++ = *src++;
		count++;
	}
	if (count < size)
		*dest = 0;
	while (*src)
	{
		src++;
		count++;
	}
	return (count);
}
