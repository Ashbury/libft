/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmapper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:22:23 by justasze          #+#    #+#             */
/*   Updated: 2018/01/01 16:16:11 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	end_free(void)
{
	t_mapped_zone *tmp;

	while (g_zones != NULL)
	{
		tmp = g_zones->next;
		munmap(g_zones, g_zones->size);
		g_zones = tmp;
	}
	pthread_mutex_destroy(&g_mutex);
}
