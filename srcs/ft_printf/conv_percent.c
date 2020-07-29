/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:32:10 by Ashbury           #+#    #+#             */
/*   Updated: 2018/07/07 08:43:43 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(t_printf_data *data)
{
	data->width -= 1;
	if (!(data->flags & MINUS_FLAG))
		fill_buffer(data, data->width, data->width_symbol);
	buffer_add_char('%', data);
	if (data->flags & MINUS_FLAG)
		fill_buffer(data, data->width, data->width_symbol);
}
