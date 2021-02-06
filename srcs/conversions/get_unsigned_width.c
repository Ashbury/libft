/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:23:53 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 04:23:01 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_unsigned_width(size_t nbr, size_t base)
{
	size_t	ret;

	ret = 1;
	while (nbr /= base)
		ret++;
	return (ret);
}
