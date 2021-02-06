/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 08:49:42 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 08:52:12 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_unsigned_value(t_printf_data *data, va_list ap)
{
	size_t	ret;

	if (data->length >= LL_LENGTH)
		ret = va_arg(ap, size_t);
	else if (data->length == L_LENGTH)
		ret = (unsigned long)va_arg(ap, unsigned long);
	else if (data->length == H_LENGTH)
		ret = (unsigned short)va_arg(ap, unsigned int);
	else if (data->length == HH_LENGTH)
		ret = (unsigned char)va_arg(ap, unsigned int);
	else
		ret = va_arg(ap, unsigned int);
	return (ret);
}
