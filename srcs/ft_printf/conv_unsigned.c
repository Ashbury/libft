/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 19:44:12 by Ashbury           #+#    #+#             */
/*   Updated: 2018/07/07 09:17:05 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flags(t_printf_data *data, size_t nbr, size_t nbr_width,
							size_t sharp_length)
{
	data->precision -= nbr_width;
	if (data->precision > 0)
		data->width -= data->precision;
	data->width -= sharp_length;
	if (!(data->flags & MINUS_FLAG))
	{
		if (data->flags & SHARP_FLAG && data->width_symbol == '0'
			&& nbr != 0)
			buffer_add_string(data->conv.sharp_str, data, sharp_length);
		if (!(data->flags & POINT_FLAG && nbr == 0))
			data->width -= nbr_width;
		fill_buffer(data, data->width, data->width_symbol);
	}
	if ((data->flags & SHARP_FLAG && data->width_symbol != '0'
		&& nbr != 0) || (data->flags & POINT_FLAG
		&& data->conv.base_len == 8 && nbr == 0))
	{
		buffer_add_string(data->conv.sharp_str, data, sharp_length);
		if (data->conv.base_len == 8)
			data->precision--;
	}
}

void		conv_unsigned(t_printf_data *data, va_list ap)
{
	size_t	nbr;
	size_t	nbr_width;
	size_t	sharp_length;

	if (data->flags & SHARP_FLAG)
		sharp_length = ft_strlen(data->conv.sharp_str);
	else
		sharp_length = 0;
	nbr = get_unsigned_value(data, ap);
	nbr_width = get_unsigned_width(nbr, data->conv.base_len);
	handle_flags(data, nbr, nbr_width, sharp_length);
	fill_buffer(data, data->precision, '0');
	if (!(data->flags & POINT_FLAG && data->precision <= 0 && nbr == 0))
		buffer_add_unsigned(nbr, data);
	if (data->flags & MINUS_FLAG)
	{
		if (!(data->flags & POINT_FLAG && nbr == 0))
			data->width -= nbr_width;
		fill_buffer(data, data->width, data->width_symbol);
	}
}
