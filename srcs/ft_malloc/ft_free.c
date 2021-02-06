/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:55:25 by justasze          #+#    #+#             */
/*   Updated: 2018/01/01 18:17:00 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void				remove_zone(t_mapped_zone *zone)
{
	t_mapped_zone **indirect;

	indirect = &g_zones;
	while (*indirect != zone)
		indirect = &(*indirect)->next;
	*indirect = zone->next;
	munmap(zone, zone->size);
}

static void				rm_page_and_fragment(t_mapped_zone *zone, t_page *page)
{
	t_page	*tmp;

	tmp = zone->pages;
	page->is_used = 0;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->is_used == 1 || tmp->next->is_used == 1)
		{
			tmp = tmp->next;
			continue ;
		}
		tmp->size += tmp->next->size + sizeof(t_page);
		tmp->next = tmp->next->next;
		if (tmp->next == NULL)
		{
			zone->used_size -= (tmp->size + sizeof(t_page));
			return ;
		}
		tmp = tmp->next;
	}
	if (page->next == NULL)
		zone->used_size -= (page->size + sizeof(t_page));
}

/*
** LARGE zones are munmapped; Others are only fragmented and will be unmapped
** by a destructor function at the end on the program.
*/

static void				remove_or_fragment(t_mapped_zone *zone, void *ptr)
{
	t_page	*page;

	page = zone->pages;
	if (page == NULL && ptr == (void*)((char*)zone + sizeof(t_mapped_zone)))
		remove_zone(zone);
	else
	{
		while (page != NULL && page->next != NULL)
		{
			if (ptr > (void*)page && ptr < (void*)(page->next))
				break ;
			page = page->next;
		}
		if (ptr == (void*)((char*)page + sizeof(t_page)))
			rm_page_and_fragment(zone, page);
	}
}

void					ft_free(void *ptr)
{
	t_mapped_zone	*zone;

	pthread_mutex_lock(&g_mutex);
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	zone = ft_find_zone(ptr);
	if (zone != NULL)
		remove_or_fragment(zone, ptr);
	pthread_mutex_unlock(&g_mutex);
	return ;
}
