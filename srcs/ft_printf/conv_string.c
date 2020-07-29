/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:39:12 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 08:44:11 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_string(t_printf_data *data, va_list ap)
{
	char	*str;
	size_t	len;

	if (data->length >= L_LENGTH)
		conv_unicode_string(data, va_arg(ap, wchar_t *));
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		len = ft_strlen(str);
		if (data->flags & POINT_FLAG && data->precision >= 0
			&& (size_t)data->precision <= len)
			len = (size_t)data->precision;
		data->width -= len;
		if (!(data->flags & MINUS_FLAG))
			fill_buffer(data, data->width, data->width_symbol);
		buffer_add_string(str, data, len);
		if (data->flags & MINUS_FLAG)
			fill_buffer(data, data->width, data->width_symbol);
	}
}
