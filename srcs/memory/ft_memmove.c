/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:36:10 by justasze          #+#    #+#             */
/*   Updated: 2015/11/27 10:26:15 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO : This can be way better.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*a;
	const char	*b;

	a = dst;
	b = src;
	if (a <= b || b >= (a + len))
	{
		while (len--)
			*a++ = *b++;
	}
	else
	{
		a = a + len - 1;
		b = b + len - 1;
		while (len--)
			*a-- = *b--;
	}
	return (dst);
}
