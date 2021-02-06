/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unicode_char_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 04:39:45 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 04:48:45 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_unicode_char_width(wchar_t c)
{
	size_t	width;

	width = get_unsigned_width((unsigned int)c, 2);
	if (width <= 7)
		return (1);
	else if (width <= 11)
		return (2);
	else if (width <= 16)
		return (3);
	else
		return (4);
}
