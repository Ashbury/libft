/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:01:51 by justasze          #+#    #+#             */
/*   Updated: 2018/01/01 17:53:41 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*add_page(t_mapped_zone *zone, t_page *page, size_t size)
{
	t_page	*tmp;

	tmp = NULL;
	if (page->is_used == 0)
	{
		page->is_used = 1;
		page->size = size;
		tmp = page;
		zone->used_size += page->size + sizeof(t_page);
	}
	else
	{
		page->next = (void*)((char*)page + sizeof(t_page) + page->size);
		tmp = page->next;
		tmp->size = size;
		tmp->is_used = 1;
		zone->used_size += size + sizeof(t_page);
		tmp->next = NULL;
	}
	return ((void*)((char*)tmp + sizeof(t_page)));
}

static void	*page_setup(t_mapped_zone *zone, t_page *page, size_t size)
{
	t_page	*tmp;

	(void)zone;
	page->is_used = 1;
	if (page->size - size <= sizeof(t_page) + ALIGNMENT)
		return ((void*)((char*)page + sizeof(t_page)));
	tmp = page->next;
	page->next = (void*)((char*)page + sizeof(t_page) + size);
	page->next->size = page->size - size - sizeof(t_page);
	page->next->is_used = 0;
	page->next->next = tmp;
	page->size = size;
	return ((void*)((char*)page + sizeof(t_page)));
}

static int	is_suitable(t_page *page, size_t size)
{
	if (page->is_used == 0 && page->size >= size)
		return (1);
	return (0);
}

/*
** Here, I assume that there is always at last one page
** and that memory is always defragmented by my free.
*/

static void	*find_available_page(t_mapped_zone *zone, size_t size)
{
	t_page	*page;

	page = zone->pages;
	while (page->next != NULL)
	{
		if (is_suitable(page, size))
			return (page_setup(zone, page, size));
		page = page->next;
	}
	if (zone->size <= zone->used_size
		|| zone->size - zone->used_size < (size + sizeof(t_page)))
		return (NULL);
	return (add_page(zone, page, size));
}

void		*get_page(size_t size)
{
	void			*ret;
	t_mapped_zone	*zone;
	size_t			zone_size;
	size_t			page_size;

	zone_size = size > TINY_CAP ? SMALL_ZONE_SIZE : TINY_ZONE_SIZE;
	zone = g_zones;
	page_size = (size_t)getpagesize();
	while (zone != NULL)
	{
		if (zone->size / (size_t)getpagesize() == zone_size
			|| (zone_size == TINY_ZONE_SIZE && zone->size == page_size))
		{
			ret = find_available_page(zone, size);
			if (ret != NULL)
				return (ret);
		}
		zone = zone->next;
	}
	return (NULL);
}
