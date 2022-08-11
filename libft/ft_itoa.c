/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:15:04 by jiwkwon           #+#    #+#             */
/*   Updated: 2021/12/06 11:29:57 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	if (n < 0)
		return (count + 1);
	else
		return (count);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*a;
	unsigned int	nbr;

	len = get_length(n);
	a = (char *)ft_calloc(sizeof(char), len + 1);
	if (a == NULL)
		return (NULL);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	a[len--] = '\0';
	while (len >= 0)
	{
		a[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}
