/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 07:03:24 by justasze          #+#    #+#             */
/*   Updated: 2018/06/14 11:22:32 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO: Refactor that casting thing.
** Casting it into a uint64_t array might be good,
** since malloc always align memory, no ni possible crash,
** and good optmisation. Tests required.
*/

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	if ((mem = malloc(sizeof(char) * size)))
	{
		while (i < size)
		{
			*(unsigned char *)((unsigned long)mem + i) = 0;
			i++;
		}
		return (mem);
	}
	return (NULL);
}
