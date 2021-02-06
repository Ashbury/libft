/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:16:45 by justasze          #+#    #+#             */
/*   Updated: 2018/10/04 14:18:43 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** TODO: No recursivity, please.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		if (del != NULL)
			del(((*alst)->content), ((*alst)->content_size));
		ft_lstdel(&(*alst)->next, del);
		free(*alst);
		*alst = NULL;
	}
}
