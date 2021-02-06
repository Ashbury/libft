/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_conv.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:05:18 by Ashbury           #+#    #+#             */
/*   Updated: 2018/07/06 08:17:51 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_CONV_H

# define S_PRINTF_CONV_H

# include "libft.h"

typedef struct	s_printf_conv
{
	size_t		base_len;
	size_t		conv_length;
	char		*sharp_str;
	char		*base;
}				t_printf_conv;

#endif
