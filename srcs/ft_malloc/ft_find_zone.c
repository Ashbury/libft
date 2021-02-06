/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_zone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:22:50 by justasze          #+#    #+#             */
/*   Updated: 2017/12/30 16:37:25 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_mapped_zone	*ft_find_zone(void *ptr)
{
	t_mapped_zone	*zone;

	zone = g_zones;
	if (ptr < (void*)zone)
		return (NULL);
	while (zone->next != NULL)
	{
		if (ptr > (void*)zone && ptr < (void*)(zone->next))
			break ;
		zone = zone->next;
	}
	return (zone);
}
