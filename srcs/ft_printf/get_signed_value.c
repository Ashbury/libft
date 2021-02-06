/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 08:46:28 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 08:56:56 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	get_signed_value(t_printf_data *data, va_list ap)
{
	ssize_t ret;

	if (data->length >= LL_LENGTH)
		ret = va_arg(ap, ssize_t);
	else if (data->length >= L_LENGTH)
		ret = (long)va_arg(ap, long);
	else if (data->length >= H_LENGTH)
		ret = (short)va_arg(ap, int);
	else if (data->length >= HH_LENGTH)
		ret = (char)va_arg(ap, int);
	else
		ret = va_arg(ap, int);
	return (ret);
}
