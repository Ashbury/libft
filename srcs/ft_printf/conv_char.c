/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:30:41 by Ashbury           #+#    #+#             */
/*   Updated: 2018/07/07 08:43:27 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_char(t_printf_data *data, va_list ap)
{
	wchar_t	c;

	if (data->length >= L_LENGTH)
	{
		c = va_arg(ap, wchar_t);
		conv_unicode_char(data, c, get_unicode_char_width(c), 1);
	}
	else
	{
		data->width -= 1;
		if (!(data->flags & MINUS_FLAG))
			fill_buffer(data, data->width, data->width_symbol);
		buffer_add_char((char)va_arg(ap, int), data);
		if (data->flags & MINUS_FLAG)
			fill_buffer(data, data->width, data->width_symbol);
	}
}
