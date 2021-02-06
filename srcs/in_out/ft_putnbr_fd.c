/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:29:34 by justasze          #+#    #+#             */
/*   Updated: 2016/05/06 17:24:25 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int64_t *nbr, char *converted)
{
	size_t	i;
	int64_t	tmp;

	i = 0;
	if (*nbr < 0)
	{
		converted[0] = '-';
		*nbr *= -1;
		i++;
	}
	tmp = *nbr;
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

void			ft_putnbr_fd(int32_t n, int fd)
{
	char	converted[12];
	int64_t	nbr;
	size_t	i;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	nbr = (int64_t)n;
	i = get_len(&nbr, converted);
	converted[i] = 0;
	i--;
	while (nbr)
	{
		converted[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	ft_putstr_fd(converted, fd);
}
