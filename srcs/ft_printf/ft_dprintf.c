/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:34:50 by justasze          #+#    #+#             */
/*   Updated: 2018/09/27 18:23:22 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_arg_properties(t_printf_data *data)
{
	data->length = 0;
	data->width = 0;
	data->width_symbol = ' ';
	data->flags = 0;
	data->precision = 0;
}

static void	init_data(t_printf_data *data, int fd)
{
	data->ret = 0;
	data->format_position = 0;
	data->buffer_position = 0;
	data->fd = fd;
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_printf_data	data;
	va_list			ap;
	unsigned int	format_len;

	init_data(&data, fd);
	va_start(ap, format);
	format_len = (unsigned int)ft_strlen(format);
	while (data.format_position < format_len)
	{
		if (format[data.format_position] == '%')
		{
			reset_arg_properties(&data);
			data.format_position += 1;
			parse_argument(&data, format, ap);
			treat_argument(&data, ap, format[data.format_position]);
		}
		else
			buffer_add_char(format[data.format_position], &data);
		data.format_position += 1;
	}
	if (data.buffer_position != 0)
		write(fd, data.buffer, (size_t)data.buffer_position);
	va_end(ap);
	return (data.ret);
}
