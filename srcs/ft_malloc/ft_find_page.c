/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:30:00 by justasze          #+#    #+#             */
/*   Updated: 2018/01/01 13:07:46 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/*
** Here, I assume that the zone is not a LARGE zone.
** zone->pages is already checked non NULL.
*/

t_page	*ft_find_page(t_mapped_zone *zone, void *ptr)
{
	t_page	*ret;

	if (ptr < (void*)zone)
		return (NULL);
	ret = zone->pages;
	while (ret != NULL && ret->next != NULL)
	{
		if (ptr > (void*)ret && ptr < (void*)(ret->next))
			break ;
		ret = ret->next;
	}
	if (ptr == (void*)((char*)ret + sizeof(t_page)))
		return (ret);
	return (NULL);
}
