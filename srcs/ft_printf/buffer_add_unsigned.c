/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:03:59 by justasze          #+#    #+#             */
/*   Updated: 2018/06/18 17:05:43 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_add_unsigned(size_t nbr, t_printf_data *data)
{
	size_t	digits_begining;

	digits_begining = data->buffer_position;
	while (nbr / data->conv.base_len)
	{
		buffer_add_char(data->conv.base[nbr % data->conv.base_len], data);
		nbr /= data->conv.base_len;
	}
	buffer_add_char(data->conv.base[nbr % data->conv.base_len], data);
	data->buffer[data->buffer_position] = '\0';
	ft_strrev(&data->buffer[digits_begining]);
}
