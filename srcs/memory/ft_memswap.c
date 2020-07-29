/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:05:04 by justasze          #+#    #+#             */
/*   Updated: 2015/11/30 16:12:02 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memswap(void *m1, void *m2)
{
	void *buf;

	if ((buf = malloc(sizeof(m1))))
	{
		buf = m1;
		free(m1);
		if ((m1 = malloc(sizeof(m2))))
		{
			m1 = m2;
			free(m2);
			if ((m2 = malloc(sizeof(buf))))
			{
				m2 = buf;
				free(buf);
			}
		}
	}
}
