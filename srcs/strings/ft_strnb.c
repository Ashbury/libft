/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 21:32:17 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 06:33:28 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function returns the number of apparition
** of a character c in the given string.
** TODO: Find a better name.
*/

size_t	ft_strnb(char *str, char c)
{
	size_t	ret;

	ret = 0;
	while (*str)
	{
		if (*str == c)
			ret++;
		str++;
	}
	return (ret);
}
