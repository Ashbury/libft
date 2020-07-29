/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstparent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:53:34 by justasze          #+#    #+#             */
/*   Updated: 2015/12/29 10:32:14 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstparent(t_list *lst, t_list *item)
{
	while (lst)
	{
		if (item == lst->next)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
