/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:16:15 by justasze          #+#    #+#             */
/*   Updated: 2018/01/03 20:36:50 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	insert_zone(t_mapped_zone *new)
{
	t_mapped_zone	*prev;
	t_mapped_zone	*tmp;

	prev = NULL;
	tmp = g_zones;
	while (tmp)
	{
		if (new < tmp)
		{
			new->next = tmp;
			if (prev != NULL)
				prev->next = new;
			else
				g_zones = new;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = new;
	new->next = NULL;
	return ;
}

static void	*init_large_zone(t_mapped_zone *new, size_t zone_size)
{
	if (new == MAP_FAILED)
		return (NULL);
	new->size = zone_size;
	new->used_size = zone_size;
	new->pages = NULL;
	new->next = NULL;
	return ((void*)((char*)new + sizeof(t_mapped_zone)));
}

static void	*init_zone(t_mapped_zone *new, size_t size, size_t zone_size)
{
	if (new == MAP_FAILED)
		return (NULL);
	new->size = zone_size;
	new->pages = (void*)((char*)new + sizeof(t_mapped_zone));
	new->pages->is_used = 1;
	new->pages->size = size;
	new->pages->next = NULL;
	new->used_size = sizeof(t_mapped_zone) + sizeof(t_page) + size;
	new->next = NULL;
	return ((void*)((char*)new->pages + sizeof(t_page)));
}

static void	*map_zone(t_mapped_zone **new, size_t size)
{
	size_t		page_size;
	size_t		zone_size;

	page_size = (size_t)getpagesize();
	if (size <= TINY_CAP)
		zone_size = TINY_ZONE_SIZE * page_size;
	else if (size <= SMALL_CAP)
		zone_size = SMALL_ZONE_SIZE * page_size;
	else
	{
		zone_size = align(page_size, (size + sizeof(t_mapped_zone)));
		*new = mmap(NULL, zone_size, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
		return (init_large_zone(*new, zone_size));
	}
	*new = mmap(NULL, zone_size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	size = align(ALIGNMENT, size);
	return (init_zone(*new, size, zone_size));
}

void		add_zone(size_t size, void **ret)
{
	t_mapped_zone	*tmp;

	tmp = NULL;
	if (g_zones == NULL)
		pre_mapper();
	*ret = map_zone(&tmp, size);
	insert_zone(tmp);
	return ;
}
