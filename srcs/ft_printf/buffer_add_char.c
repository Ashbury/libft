/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:25:35 by justasze          #+#    #+#             */
/*   Updated: 2018/09/13 15:41:42 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_add_char(char c, t_printf_data *data)
{
	data->buffer[data->buffer_position] = c;
	if (data->buffer_position + 1 == FT_PRINTF_BUFF_SIZE)
	{
		write(data->fd, data->buffer, FT_PRINTF_BUFF_SIZE);
		data->buffer_position = 0;
	}
	else
		data->buffer_position += 1;
	data->ret += 1;
}
