/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:14:51 by justasze          #+#    #+#             */
/*   Updated: 2015/11/28 22:08:12 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (sizeof(dst) < sizeof(src))
		return (0);
	while (i < n && src[i])
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
