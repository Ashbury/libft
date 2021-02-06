/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 05:23:46 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 09:31:03 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_buffer(t_printf_data *data, ssize_t width, size_t symbol)
{
	while (width > 0)
	{
		buffer_add_char((char)symbol, data);
		width--;
	}
}
