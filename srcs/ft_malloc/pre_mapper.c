/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_mapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 17:29:29 by justasze          #+#    #+#             */
/*   Updated: 2018/07/05 03:27:18 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	pre_mapper(void)
{
	t_mapped_zone	*new;

	new = mmap(NULL, (size_t)getpagesize(), PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = 4096;
	new->used_size = sizeof(t_mapped_zone);
	new->pages = (void*)((char*)new + sizeof(t_mapped_zone));
	new->next = NULL;
	new->pages->is_used = 0;
	new->pages->size = TINY_CAP;
	new->pages->next = NULL;
	g_zones = new;
}
