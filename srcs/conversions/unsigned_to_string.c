/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:09:37 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 04:25:50 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*unsigned_to_string(size_t nbr, char *base, size_t base_len)
{
	size_t	size;
	char	*str;

	size = get_unsigned_width(nbr, base_len);
	if ((str = ft_strnew(size + 1)))
	{
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
