/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_endian_64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:39:29 by justasze          #+#    #+#             */
/*   Updated: 2018/08/14 14:01:29 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	rev_endian_64(uint64_t value)
{
	return (((value & 0x00000000000000FFLL) << 56) |
			((value & 0x000000000000FF00LL) << 40) |
			((value & 0x0000000000FF0000LL) << 24) |
			((value & 0x00000000FF000000LL) << 8) |
			((value & 0x000000FF00000000LL) >> 8) |
			((value & 0x0000FF0000000000LL) >> 24) |
			((value & 0x00FF000000000000LL) >> 40) |
			((value & 0xFF00000000000000LL) >> 56));
}
