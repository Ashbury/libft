/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unicode_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 02:58:40 by justasze          #+#    #+#             */
/*   Updated: 2018/07/07 09:27:37 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_unicode_string_width(wchar_t *str)
{
	size_t	ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret += get_unicode_char_width(str[i]);
		i++;
	}
	return (ret);
}

static size_t	handle_width(t_printf_data *data, wchar_t *str, size_t *width)
{
	size_t	i;
	size_t	char_width;
	size_t	ret;

	i = 0;
	ret = 0;
	if (data->flags & POINT_FLAG && data->precision >= 0
		&& (size_t)data->precision <= *width)
	{
		while (str[i])
		{
			char_width = get_unicode_char_width(str[i]);
			if (*width < char_width)
				break ;
			*width -= char_width;
			i++;
			ret++;
		}
		data->width += *width;
	}
	else
		while (str[i++])
			ret++;
	return (ret);
}

void			conv_unicode_string(t_printf_data *data, wchar_t *str)
{
	size_t	i;
	size_t	width;
	size_t	char_width;
	size_t	to_write;

	i = 0;
	if (str == NULL)
		str = L"(null)";
	width = get_unicode_string_width(str);
	if (data->flags & POINT_FLAG && data->precision >= 0
		&& (size_t)data->precision <= width)
		width = (size_t)data->precision;
	data->width -= width;
	to_write = handle_width(data, str, &width);
	if (!(data->flags & MINUS_FLAG))
		fill_buffer(data, data->width, data->width_symbol);
	while (i < to_write)
	{
		char_width = get_unicode_char_width(str[i]);
		conv_unicode_char(data, str[i++], char_width, 0);
	}
	if (data->flags & MINUS_FLAG)
		fill_buffer(data, data->width, data->width_symbol);
}
