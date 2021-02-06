/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:42:46 by justasze          #+#    #+#             */
/*   Updated: 2018/09/13 15:46:01 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_DATA_H

# define S_PRINTF_DATA_H

# include "libft.h"

typedef struct		s_printf_data
{
	int				ret;
	int				length;
	int				flags;
	int				fd;
	ssize_t			precision;
	ssize_t			width;
	size_t			width_symbol;
	size_t			buffer_position;
	size_t			format_position;
	char			buffer[FT_PRINTF_BUFF_SIZE];
	t_printf_conv	conv;
}					t_printf_data;

#endif
