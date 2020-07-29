/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:24:26 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 08:51:44 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_pointer(t_printf_data *data, va_list ap)
{
	size_t	nbr;
	size_t	nbr_width;

	nbr = get_unsigned_value(data, ap);
	nbr_width = get_unsigned_width(nbr, data->conv.base_len) + 2;
	data->precision -= nbr_width - 2;
	if (data->precision > 0)
		data->width -= data->precision;
	data->width -= nbr_width;
	if (!(data->flags & MINUS_FLAG))
	{
		if (data->width_symbol == '0')
			buffer_add_string(data->conv.sharp_str, data, 2);
		fill_buffer(data, data->width, data->width_symbol);
	}
	if (data->width_symbol != '0')
		buffer_add_string(data->conv.sharp_str, data, 2);
	fill_buffer(data, data->precision, '0');
	if (!(data->flags & POINT_FLAG && data->precision <= 0 && nbr == 0))
		buffer_add_unsigned(nbr, data);
	if (data->flags & MINUS_FLAG)
		fill_buffer(data, data->width, data->width_symbol);
}
