/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:20:03 by jshin             #+#    #+#             */
/*   Updated: 2022/02/05 17:07:24 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_copy;
	unsigned char	*src_copy;

	if (!dst && !src)
		return (NULL);
	dst_copy = dst;
	src_copy = (unsigned char *)src;
	if (dst_copy < src_copy)
		while (len--)
			*dst_copy++ = *src_copy++;
	else
	{
		dst_copy += (len - 1);
		src_copy += (len - 1);
		while (len--)
			*dst_copy-- = *src_copy--;
	}
	return (dst);
}
