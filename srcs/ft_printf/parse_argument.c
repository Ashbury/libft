/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 00:29:29 by justasze          #+#    #+#             */
/*   Updated: 2018/09/27 19:23:55 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(const char *format, t_printf_data *data)
{
	while (ft_printf_is_flag(format[data->format_position]))
	{
		if (format[data->format_position] == '+')
		{
			data->flags |= PLUS_FLAG;
			data->flags &= (~SPACE_FLAG);
		}
		else if (format[data->format_position] == ' '
			&& (data->flags & PLUS_FLAG) == 0)
			data->flags |= SPACE_FLAG;
		else if (format[data->format_position] == '-')
		{
			data->flags |= MINUS_FLAG;
			data->flags &= (~ZERO_FLAG);
		}
		else if (format[data->format_position] == '#')
			data->flags |= SHARP_FLAG;
		else if (format[data->format_position] == '0'
			&& (data->flags & MINUS_FLAG) == 0)
			data->flags |= ZERO_FLAG;
		data->format_position += 1;
	}
}

static void	get_length(const char *format, t_printf_data *data)
{
	if (format[data->format_position] == 'l'
		&& format[data->format_position + 1] == 'l')
	{
		data->format_position += 1;
		data->length |= LL_LENGTH;
	}
	else if (format[data->format_position] == 'l')
		data->length |= L_LENGTH;
	else if (format[data->format_position] == 'h'
		&& format[data->format_position + 1] == 'h')
	{
		data->format_position += 1;
		data->length |= HH_LENGTH;
	}
	else if (format[data->format_position] == 'h')
		data->length |= H_LENGTH;
	else if (format[data->format_position] == 'j')
		data->length |= J_LENGTH;
	else
		data->length |= Z_LENGTH;
	data->format_position += 1;
}

static void	get_width(const char *format, t_printf_data *data, va_list ap)
{
	int		i;
	char	str[25];

	i = 0;
	if (format[data->format_position] == '*')
	{
		data->width = va_arg(ap, ssize_t);
		data->format_position++;
		return ;
	}
	while (ft_isdigit(format[data->format_position]))
	{
		str[i++] = format[data->format_position];
		data->format_position++;
	}
	str[i] = '\0';
	data->width = ft_atoi(str);
}

static void	get_precision(const char *format, t_printf_data *data, va_list ap)
{
	int		i;
	char	str[25];

	i = 0;
	data->format_position++;
	data->flags |= POINT_FLAG;
	if (format[data->format_position] == '*')
	{
		data->width = va_arg(ap, ssize_t);
		data->format_position++;
		return ;
	}
	while (ft_isdigit(format[data->format_position]))
	{
		str[i++] = format[data->format_position];
		data->format_position++;
	}
	str[i] = '\0';
	data->precision = ft_atoi(str);
}

void		parse_argument(t_printf_data *data, const char *format, va_list ap)
{
	while (format[data->format_position])
	{
		if (ft_printf_is_flag(format[data->format_position]))
			get_flags(format, data);
		else if (ft_printf_is_size(format[data->format_position]))
			get_length(format, data);
		else if (ft_isdigit(format[data->format_position])
			|| format[data->format_position] == '*')
			get_width(format, data, ap);
		else if (format[data->format_position] == '.')
			get_precision(format, data, ap);
		else
			return ;
	}
}
