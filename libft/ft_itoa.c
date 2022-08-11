/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:19:30 by jshin             #+#    #+#             */
/*   Updated: 2021/12/06 18:22:31 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennum(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	r;

	r = n;
	len = lennum(r);
	if (r < 0)
	{
		len++;
		r = -1 * r;
	}
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = 0;
	while (len > 0)
	{
		p[len - 1] = r % 10 + '0';
		r /= 10;
		len--;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}
