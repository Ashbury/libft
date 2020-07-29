/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:23:30 by justasze          #+#    #+#             */
/*   Updated: 2016/05/07 13:34:08 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*((const unsigned char *)((unsigned long)s)) == (unsigned char)c)
			return ((unsigned char *)(((unsigned long)s)));
		s = (const void*)((unsigned long)s + 1);
	}
	return (NULL);
}
