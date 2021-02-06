/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 05:20:59 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 09:26:23 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_invalid(t_printf_data *data, char c)
{
	if (!(data->flags & MINUS_FLAG))
	{
		data->width -= 1;
		fill_buffer(data, data->width, data->width_symbol);
	}
	buffer_add_char(c, data);
	if (data->flags & MINUS_FLAG)
	{
		data->width -= 1;
		fill_buffer(data, data->width, data->width_symbol);
	}
}
