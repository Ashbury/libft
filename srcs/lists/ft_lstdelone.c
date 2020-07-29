/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:35:08 by justasze          #+#    #+#             */
/*   Updated: 2018/10/19 18:32:22 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** TODO: Refactor that.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del(((*alst)->content), ((*alst)->content_size));
	free(*alst);
	*alst = NULL;
}
