/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:19:46 by justasze          #+#    #+#             */
/*   Updated: 2018/01/25 17:20:25 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t	get_len(size_t value, size_t base)
{
	size_t	i;
	size_t	prefill;

	i = 0;
	prefill = (base == 16) ? 2 : 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i + prefill);
}

void			ft_put_size_t(size_t value)
{
	size_t	i;
	size_t	len;
	char	ret[13];

	if (value == 0)
	{
		ft_putstr("0");
		return ;
	}
	i = get_len(value, 10);
	len = i;
	ret[i] = '\0';
	i--;
	while (value)
	{
		ret[i] = (value % 10) + '0';
		value /= 10;
		i--;
	}
	ft_putstr(ret);
}

void			ft_put_addr(size_t value, size_t end_of_line)
{
	size_t	i;
	size_t	len;
	char	ret[13];

	i = get_len(value, 16);
	len = i;
	ret[i] = '\0';
	ret[0] = '0';
	ret[1] = 'x';
	i--;
	while (value)
	{
		ret[i] = HEX_BASE[value % 16];
		value /= 16;
		i--;
	}
	if (end_of_line != 0)
	{
		ret[len] = '\n';
		len += 1;
		ret[len] = '\0';
	}
	ft_putstr(ret);
}
