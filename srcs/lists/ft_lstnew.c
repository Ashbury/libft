/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:19:11 by justasze          #+#    #+#             */
/*   Updated: 2015/11/30 15:53:42 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list)
	{
		if (!content)
		{
			if ((list->content = malloc(content_size * sizeof(char))))
			{
				list->content = NULL;
				list->content_size = 0;
				list->next = NULL;
				return (list);
			}
		}
		else if ((list->content = malloc(content_size * sizeof(char))))
		{
			list->content = ft_memmove(list->content, content, content_size);
			list->content_size = content_size;
			list->next = NULL;
			return (list);
		}
	}
	return (NULL);
}
