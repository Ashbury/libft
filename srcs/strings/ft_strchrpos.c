/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 13:28:50 by justasze          #+#    #+#             */
/*   Updated: 2018/12/08 09:43:56 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchrpos(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
