/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add_signed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:57:31 by justasze          #+#    #+#             */
/*   Updated: 2018/09/13 15:41:59 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_add_signed(ssize_t nbr, t_printf_data *data)
{
	size_t	digits_beginning;
	size_t	base_len;

	base_len = data->conv.base_len;
	if (nbr < 0)
	{
		buffer_add_char('-', data);
		nbr *= -1;
	}
	digits_beginning = data->buffer_position;
	while ((size_t)nbr / base_len)
	{
		buffer_add_char(data->conv.base[(size_t)nbr % base_len], data);
		nbr /= base_len;
	}
	buffer_add_char(data->conv.base[(size_t)nbr % base_len], data);
	data->buffer[data->buffer_position] = '\0';
	ft_strrev(&data->buffer[digits_beginning]);
}
