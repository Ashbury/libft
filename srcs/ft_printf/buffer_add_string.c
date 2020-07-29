/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:27:33 by justasze          #+#    #+#             */
/*   Updated: 2018/09/13 15:42:14 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_long_string(char *str, size_t len, t_printf_data *data)
{
	if (data->buffer_position != 0)
		write(data->fd, data->buffer, (size_t)data->buffer_position);
	write(data->fd, str, (size_t)len);
	data->buffer_position = 0;
}

static void	handle_basic_string(char *str, size_t len, t_printf_data *data)
{
	size_t	i;

	if (data->buffer_position + len >= FT_PRINTF_BUFF_SIZE)
	{
		write(data->fd, data->buffer, (size_t)data->buffer_position);
		data->buffer_position = 0;
	}
	i = 0;
	while (i < len)
	{
		data->buffer[data->buffer_position + i] = str[i];
		i++;
	}
	data->buffer_position += len;
}

void		buffer_add_string(char *str, t_printf_data *data, size_t len)
{
	if (len >= FT_PRINTF_BUFF_SIZE)
		handle_long_string(str, len, data);
	else
		handle_basic_string(str, len, data);
	data->ret += len;
}
