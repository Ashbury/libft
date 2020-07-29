/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:52:27 by justasze          #+#    #+#             */
/*   Updated: 2018/04/25 16:15:17 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long nbr)
{
	size_t	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	long	conv;
	size_t	size;
	char	*str;

	size = get_len(n);
	conv = n;
	if ((str = ft_strnew(size + 1)))
	{
		if (conv < 0)
		{
			conv *= -1;
			str[0] = '-';
		}
		size--;
		while (conv / 10)
		{
			str[size] = (conv % 10 + '0');
			conv /= 10;
			size--;
		}
		str[size] = (conv % 10 + '0');
		return (str);
	}
	return (NULL);
}
