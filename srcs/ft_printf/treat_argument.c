/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:48:54 by justasze          #+#    #+#             */
/*   Updated: 2018/09/13 15:43:33 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_up_conv(t_printf_data *data, size_t base_len,
						char *sharp, char *base)
{
	data->conv.base_len = base_len;
	data->conv.sharp_str = sharp;
	data->conv.base = base;
	return (1);
}

static void	treat_argument_bis(t_printf_data *data, va_list ap, char type)
{
	wchar_t	c;

	if (type == '%')
		conv_percent(data);
	else if (type == 'S')
		conv_unicode_string(data, va_arg(ap, wchar_t *));
	else if (type == 'C')
	{
		c = va_arg(ap, wchar_t);
		conv_unicode_char(data, c, get_unicode_char_width(c), 1);
	}
	else if (type == 'D' && set_up_conv(data, 10, "", "0123456789")
		&& (data->length = LL_LENGTH))
		conv_signed(data, ap);
	else if (type == 'U' && set_up_conv(data, 10, "", "0123456789")
		&& (data->length = LL_LENGTH))
		conv_unsigned(data, ap);
	else if (type == 'O' && set_up_conv(data, 8, "0", "01234567")
		&& (data->length = LL_LENGTH))
		conv_unsigned(data, ap);
	else if (type)
		conv_invalid(data, type);
}

void		treat_argument(t_printf_data *data, va_list ap, char type)
{
	if (data->flags & ZERO_FLAG)
		data->width_symbol = '0';
	if ((type == 'd' || type == 'i') && set_up_conv(data, 10, "", "0123456789"))
		conv_signed(data, ap);
	else if (type == 'u' && set_up_conv(data, 10, "", "0123456789"))
		conv_unsigned(data, ap);
	else if (type == 'x' && set_up_conv(data, 16, "0x", "0123456789abcdef"))
		conv_unsigned(data, ap);
	else if (type == 's')
		conv_string(data, ap);
	else if (type == 'c')
		conv_char(data, ap);
	else if (type == 'p')
	{
		data->length = Z_LENGTH;
		data->flags |= SHARP_FLAG;
		set_up_conv(data, 16, "0x", "0123456789abcdef");
		conv_pointer(data, ap);
	}
	else if (type == 'X' && set_up_conv(data, 16, "0X", "0123456789ABCDEF"))
		conv_unsigned(data, ap);
	else if (type == 'o' && set_up_conv(data, 8, "0", "01234567"))
		conv_unsigned(data, ap);
	else
		treat_argument_bis(data, ap, type);
}
