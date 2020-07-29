/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 04:11:59 by justasze          #+#    #+#             */
/*   Updated: 2016/05/07 13:32:46 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((const unsigned char *)(src))[i];
		if (((const unsigned char *)src)[i] == (unsigned char)c)
			return ((void *)((unsigned long)dst + i + 1));
		i++;
	}
	return (NULL);
}
