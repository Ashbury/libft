/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unicode_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 02:22:57 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 08:59:40 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	two_bytes(unsigned int *value, size_t mask1, t_printf_data *data,
						int flags)
{
	unsigned char	byte;

	if (flags && !(data->flags & MINUS_FLAG))
	{
		data->width -= 2;
		fill_buffer(data, data->width, data->width_symbol);
	}
	byte = (unsigned char)((mask1 >> 8) | ((*value >> 6) << 27) >> 27);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask1 << 24) >> 24) | (*value << 26) >> 26);
	buffer_add_char((char)byte, data);
	if (flags && (data->flags & MINUS_FLAG))
	{
		data->width -= 2;
		fill_buffer(data, data->width, data->width_symbol);
	}
}

static void	three_bytes(unsigned int *value, size_t mask2, t_printf_data *data,
						int flags)
{
	unsigned char	byte;

	if (flags && !(data->flags & MINUS_FLAG))
	{
		data->width -= 3;
		fill_buffer(data, data->width, data->width_symbol);
	}
	byte = (unsigned char)((mask2 >> 16) | ((*value >> 12) << 28) >> 28);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask2 << 16) >> 24) | ((*value >> 6) << 26) >> 26);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask2 << 24) >> 24) | (*value << 26) >> 26);
	buffer_add_char((char)byte, data);
	if (flags && (data->flags & MINUS_FLAG))
	{
		data->width -= 3;
		fill_buffer(data, data->width, data->width_symbol);
	}
}

static void	four_bytes(unsigned int *value, size_t mask3, t_printf_data *data,
						int flags)
{
	unsigned char	byte;

	if (flags && !(data->flags & MINUS_FLAG))
	{
		data->width -= 4;
		fill_buffer(data, data->width, data->width_symbol);
	}
	byte = (unsigned char)((mask3 >> 24) | ((*value >> 18) << 29) >> 29);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask3 << 8) >> 24) | ((*value >> 12) << 29) >> 29);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask3 << 16) >> 24) | ((*value >> 6) << 26) >> 26);
	buffer_add_char((char)byte, data);
	byte = (unsigned char)(((mask3 << 24) >> 24) | (*value << 26) >> 26);
	buffer_add_char((char)byte, data);
	if (flags && (data->flags & MINUS_FLAG))
	{
		data->width -= 4;
		fill_buffer(data, data->width, data->width_symbol);
	}
}

void		conv_unicode_char(t_printf_data *data, wchar_t value,
								size_t width, int flags)
{
	unsigned int	v;

	v = (unsigned int)value;
	if (width == 1)
	{
		if (flags && !(data->flags & MINUS_FLAG))
		{
			data->width -= 1;
			fill_buffer(data, data->width, data->width_symbol);
		}
		buffer_add_char((char)value, data);
		if (flags && (data->flags & MINUS_FLAG))
		{
			data->width -= 1;
			fill_buffer(data, data->width, data->width_symbol);
		}
	}
	else if (width == 2)
		two_bytes(&v, 49280, data, flags);
	else if (width <= 3)
		three_bytes(&v, 14712960, data, flags);
	else
		four_bytes(&v, 4034953344, data, flags);
}
