/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_logs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:48:10 by justasze          #+#    #+#             */
/*   Updated: 2018/01/02 10:36:49 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		show_large_zone(t_mapped_zone *z, t_memory_logs *logs)
{
	ft_putstr("LARGE : ");
	ft_put_addr((size_t)z, 1);
	ft_put_addr((size_t)((char *)z + sizeof(t_mapped_zone)), 0);
	ft_putstr(" - ");
	ft_put_addr((size_t)((char *)z + sizeof(t_mapped_zone) + z->size), 0);
	ft_putstr(" : ");
	ft_put_size_t(z->size - sizeof(t_mapped_zone));
	ft_putstr(" octets\n");
	logs->used_bytes += z->size - sizeof(t_mapped_zone);
}

static void		print_page_specs(t_page *page, t_memory_logs *logs)
{
	if (page->is_used == 1 || logs->advanced_logs == 1)
	{
		ft_put_addr((size_t)((char *)page + sizeof(t_page)), 0);
		ft_putstr(" - ");
		ft_put_addr((size_t)((char *)page + sizeof(t_page) + page->size), 0);
		ft_putstr(" : ");
		ft_put_size_t(page->size);
		if (page->is_used == 1)
		{
			ft_putstr(" octets\n");
			logs->used_bytes += page->size;
		}
		else
		{
			ft_putstr(" octets (unused)\n");
			logs->unused_bytes += page->size;
		}
	}
}

static void		print_zone_type(t_mapped_zone *zone, t_memory_logs *logs)
{
	logs->mapped_bytes += zone->size;
	if (zone->pages == NULL)
	{
		show_large_zone(zone, logs);
		return ;
	}
	else if (zone->size / (size_t)getpagesize() == TINY_ZONE_SIZE
			|| zone->size == (size_t)getpagesize())
		ft_putstr("TINY : ");
	else
		ft_putstr("SMALL : ");
	ft_put_addr((size_t)zone, 1);
}

static void		print_end_logs(t_memory_logs *logs)
{
	if (logs->advanced_logs == 0)
	{
		ft_putstr("Total : ");
		ft_put_size_t(logs->used_bytes);
		ft_putstr(" octets\n");
	}
	else
	{
		ft_putstr("Mapped bytes : ");
		ft_put_size_t(logs->mapped_bytes);
		ft_putstr(" (");
		ft_put_size_t(logs->mapped_bytes / (size_t)getpagesize());
		ft_putstr(" pages)\n");
		ft_putstr("Used bytes : ");
		ft_put_size_t(logs->used_bytes);
		ft_putstr(" octets\n");
		ft_putstr("Unused bytes : ");
		ft_put_size_t(logs->unused_bytes);
		ft_putstr(" octets\n");
	}
}

void			show_alloc_mem(void)
{
	t_mapped_zone	*zone;
	t_page			*page;
	t_memory_logs	logs;

	pthread_mutex_lock(&g_mutex);
	logs.mapped_bytes = 0;
	logs.used_bytes = 0;
	logs.unused_bytes = 0;
	logs.advanced_logs = getenv("MALLOC_ADVANCED_LOGS") != NULL ? 1 : 0;
	zone = g_zones;
	while (zone != NULL)
	{
		print_zone_type(zone, &logs);
		page = zone->pages;
		while (page != NULL)
		{
			print_page_specs(page, &logs);
			page = page->next;
		}
		zone = zone->next;
	}
	print_end_logs(&logs);
	pthread_mutex_unlock(&g_mutex);
}
