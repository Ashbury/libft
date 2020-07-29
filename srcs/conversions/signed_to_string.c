/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:05:50 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 04:25:27 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Notes:
** First, here, I don't do two's complement: in hexadecimal
** (or any other base), -42 = -0x2A
** Second, here, I don't handle the absolute minimal value
** (-9223372036854775808) since no matter how I represent it (in litteral
** or with SSIZE_MAX + 1), I get a warning at compilation. Shame indeed.
*/

char	*signed_to_string(ssize_t nbr, char *base, ssize_t base_len)
{
	size_t	size;
	char	*str;

	size = get_signed_width(nbr, base_len);
	if ((str = ft_strnew(size + 1)))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			str[0] = '-';
		}
		size--;
		while (nbr / base_len)
		{
			str[size] = base[nbr % base_len];
			nbr /= base_len;
			size--;
		}
		str[size] = (base[nbr % base_len]);
		return (str);
	}
	return (NULL);
}
