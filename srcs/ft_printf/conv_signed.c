/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:32:49 by Ashbury           #+#    #+#             */
/*   Updated: 2018/07/07 09:21:35 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flags(t_printf_data *data, ssize_t *nbr,
							char space_plus_flag, char space_plus_symbol)
{
	size_t	nbr_width;

	nbr_width = get_signed_width(*nbr, (ssize_t)data->conv.base_len);
	if (space_plus_flag && *nbr >= 0)
		data->width -= 1;
	data->width -= (data->precision > (int)nbr_width)
		? data->precision : (int)nbr_width;
	if (*nbr == 0 && data->flags & POINT_FLAG && data->precision <= 0)
		data->width++;
	if (*nbr != 0)
		data->precision -= nbr_width;
	if (!(data->flags & MINUS_FLAG))
	{
		if (data->width_symbol == '0' && *nbr < 0)
		{
			buffer_add_char('-', data);
			*nbr *= -1;
		}
		else if (space_plus_flag && *nbr >= 0)
		{
			if (data->width_symbol == '0')
				buffer_add_char(space_plus_symbol, data);
		}
		fill_buffer(data, data->width, data->width_symbol);
	}
}

void		conv_signed(t_printf_data *data, va_list ap)
{
	ssize_t	nbr;
	char	space_plus_flag;
	char	space_plus_symbol;

	space_plus_flag = (data->flags & PLUS_FLAG || data->flags & SPACE_FLAG);
	space_plus_symbol = data->flags & PLUS_FLAG ? '+' : ' ';
	if (data->flags & POINT_FLAG)
		data->width_symbol = ' ';
	nbr = get_signed_value(data, ap);
	if (nbr < 0)
		data->precision += 1;
	handle_flags(data, &nbr, space_plus_flag, space_plus_symbol);
	if (space_plus_flag && nbr >= 0 && data->width_symbol != '0')
		buffer_add_char(space_plus_symbol, data);
	if (data->precision > 0 && nbr < 0)
	{
		buffer_add_char('-', data);
		nbr *= -1;
	}
	fill_buffer(data, data->precision, '0');
	if (nbr != 0 || (nbr == 0 &&
		(!(data->flags & POINT_FLAG) || data->precision < 0)))
		buffer_add_signed(nbr, data);
	if (data->flags & MINUS_FLAG)
		fill_buffer(data, data->width, data->width_symbol);
}
