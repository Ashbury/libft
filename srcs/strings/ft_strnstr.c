/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 05:33:03 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 06:33:37 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO : Refactor that.
*/

char	*ft_strnstr(char *str1, char *str2, size_t n)
{
	size_t	len2;

	if (*str2 == '\0')
		return ((char*)str1);
	len2 = ft_strlen(str2);
	while (*str1 != '\0' && n-- >= len2)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, len2) == 0)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
