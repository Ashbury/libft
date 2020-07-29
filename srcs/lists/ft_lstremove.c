/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:25:45 by justasze          #+#    #+#             */
/*   Updated: 2018/10/19 18:41:05 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremove(t_list **indirect, t_list *entry)
{
	while (*indirect != entry)
		indirect = &(*indirect)->next;
	*indirect = entry->next;
	free(entry->content);
	entry->content = NULL;
	free(entry);
}
