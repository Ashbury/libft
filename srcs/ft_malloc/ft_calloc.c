/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 10:27:52 by justasze          #+#    #+#             */
/*   Updated: 2018/01/02 16:23:40 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	total;
	size_t	i;

	i = 0;
	total = align(ALIGNMENT, count * size);
	ret = ft_malloc(total);
	if (ret == NULL)
		return (NULL);
	while (i < total)
	{
		((uint8_t*)ret)[i] = 0;
		i++;
	}
	return (ret);
}
