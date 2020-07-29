/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:14:04 by justasze          #+#    #+#             */
/*   Updated: 2018/01/02 16:23:38 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>

t_mapped_zone	*g_zones;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		*ft_malloc(size_t size)
{
	void	*ret;

	pthread_mutex_lock(&g_mutex);
	ret = NULL;
	if (size == 0)
	{
		pthread_mutex_unlock(&g_mutex);
		return (NULL);
	}
	size = align(ALIGNMENT, size);
	if (size > SMALL_CAP || !(ret = get_page(size)))
		add_zone(size, &ret);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
