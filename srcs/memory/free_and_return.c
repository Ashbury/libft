/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:01:22 by justasze          #+#    #+#             */
/*   Updated: 2016/08/16 14:03:28 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		free_and_return(void *ptr, int ret)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ret);
}
