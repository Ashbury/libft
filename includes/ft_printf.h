/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:20:57 by Ashbury           #+#    #+#             */
/*   Updated: 2018/10/13 12:38:02 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FT_PRINTF_BUFF_SIZE 4096

# define HH_LENGTH 0x1
# define H_LENGTH 0x2
# define L_LENGTH 0x4
# define LL_LENGTH 0x8
# define Z_LENGTH 0x10
# define J_LENGTH 0x20

# define PLUS_FLAG 0x1
# define MINUS_FLAG 0x2
# define SPACE_FLAG 0x4
# define ZERO_FLAG 0x8
# define SHARP_FLAG 0x10
# define POINT_FLAG 0x20

# include "libft.h"
# include "s_printf_conv.h"
# include "s_printf_data.h"

void			buffer_add_char(char c, t_printf_data *data);
void			buffer_add_signed(ssize_t nbr, t_printf_data *data);
void			buffer_add_string(char *str, t_printf_data *data, size_t len);
void			buffer_add_unsigned(size_t nbr, t_printf_data *data);
void			conv_char(t_printf_data *data, va_list ap);
void			conv_invalid(t_printf_data *data, char c);
void			conv_percent(t_printf_data *data);
void			conv_pointer(t_printf_data *data, va_list ap);
void			conv_signed(t_printf_data *data, va_list ap);
void			conv_string(t_printf_data *data, va_list ap);
void			conv_unicode_char(t_printf_data *data, wchar_t val,
									size_t width, int flags);
void			conv_unicode_string(t_printf_data *data, wchar_t *str);
void			conv_unsigned(t_printf_data *data, va_list ap);
void			fill_buffer(t_printf_data *data, ssize_t width, size_t symbol);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf_is_flag(char c);
int				ft_printf_is_size(char c);
int				ft_printf(const char *format, ...);
ssize_t			get_signed_value(t_printf_data *data, va_list ap);
size_t			get_unicode_char_width(wchar_t c);
size_t			get_unsigned_value(t_printf_data *data, va_list ap);
void			parse_argument(t_printf_data *data, const char *format,
															va_list ap);
void			treat_argument(t_printf_data *data, va_list ap, char type);

#endif
