/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:15:48 by justasze          #+#    #+#             */
/*   Updated: 2016/05/05 19:11:17 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		p;

	if (dest == src)
		return (dest);
	p = 0;
	while ((p < size) && ((size - p) % 8))
	{
		((uint8_t *)(dest))[p] = ((const uint8_t *)(src))[p];
		p++;
	}
	while (p < size)
	{
		*(uint64_t *)((uint64_t)dest + p) =
			*(uint64_t *)((uint64_t)src + p);
		p += 8;
	}
	return (dest);
}
