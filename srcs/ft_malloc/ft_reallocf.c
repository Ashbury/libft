/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 10:47:47 by justasze          #+#    #+#             */
/*   Updated: 2018/01/01 15:44:14 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_reallocf(void *ptr, size_t size)
{
	void	*ret;

	ret = ft_realloc(ptr, size);
	if (ret == NULL)
		ft_free(ptr);
	return (ret);
}
