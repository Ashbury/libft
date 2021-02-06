/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:52:14 by justasze          #+#    #+#             */
/*   Updated: 2018/01/02 16:23:39 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*expand_page(t_mapped_zone *zone, t_page *page, size_t size)
{
	size_t	p_size;
	size_t	next_size;
	t_page	*next;

	p_size = page->size;
	zone->used_size -= p_size;
	page->size = size;
	zone->used_size += page->size + sizeof(t_page);
	if (page->next != NULL)
	{
		next_size = page->next->size;
		next = page->next->next;
		page->next = (void*)((char*)page + page->size + sizeof(t_page));
		page->next->size = next_size - size + p_size;
		page->next->is_used = 0;
		page->next->next = next;
		if (page->next->size < ALIGNMENT)
		{
			page->size += page->next->size + sizeof(t_page);
			page->next = next;
		}
	}
	return ((void*)((char*)page + sizeof(t_page)));
}

static int	can_expand_page(t_mapped_zone *zone, t_page *page, size_t size)
{
	size_t	empty_space;

	if ((page->size <= TINY_CAP && size > TINY_CAP)
		|| (page->size <= SMALL_CAP && size > SMALL_CAP))
		return (0);
	else if (page->next == NULL)
	{
		empty_space = zone->size - zone->used_size;
		if (empty_space > page->size)
			if (empty_space - page->size > size)
				return (1);
		return (0);
	}
	else if (page->next->is_used == 1)
		return (0);
	else if (page->next->size + page->size >= size)
		return (1);
	return (0);
}

static void	*ft_realloc_standard(void *ptr, t_mapped_zone *zone, size_t size)
{
	t_page	*page;
	void	*ret;

	page = ft_find_page(zone, ptr);
	if (page == NULL)
		return (NULL);
	if (size <= page->size)
		return (ptr);
	if (can_expand_page(zone, page, size))
		return (expand_page(zone, page, size));
	pthread_mutex_unlock(&g_mutex);
	ret = ft_malloc(size);
	pthread_mutex_lock(&g_mutex);
	if (ret != NULL)
	{
		ft_memcpy(ret, ptr, (page->size < size ? page->size : size));
		pthread_mutex_unlock(&g_mutex);
		ft_free(ptr);
		pthread_mutex_lock(&g_mutex);
	}
	return (ret);
}

static void	*ft_realloc_large(void *ptr, t_mapped_zone *zone, size_t size)
{
	void	*ret;

	if (ptr != (void*)((char*)zone + sizeof(t_mapped_zone)))
		return (NULL);
	if (size <= zone->size - sizeof(t_mapped_zone))
		return (ptr);
	pthread_mutex_unlock(&g_mutex);
	ret = ft_malloc(size);
	pthread_mutex_lock(&g_mutex);
	if (ret != NULL)
	{
		ret = ft_memcpy(ret, ptr, zone->size - sizeof(t_mapped_zone));
		pthread_mutex_unlock(&g_mutex);
		ft_free(ptr);
		pthread_mutex_lock(&g_mutex);
	}
	return (ret);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_mapped_zone	*zone;
	void			*ret;

	ret = NULL;
	pthread_mutex_lock(&g_mutex);
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex);
		ret = ft_malloc(size);
	}
	else if (size == 0)
	{
		pthread_mutex_unlock(&g_mutex);
		ft_free(ptr);
	}
	else if ((zone = ft_find_zone(ptr)) != NULL)
	{
		if (zone->pages == NULL)
			ret = ft_realloc_large(ptr, zone, size);
		else
			ret = ft_realloc_standard(ptr, zone, align(ALIGNMENT, size));
	}
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
