/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 02:47:50 by justasze          #+#    #+#             */
/*   Updated: 2018/08/15 12:32:12 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t size)
{
	size_t		i;
	size_t		len;
	size_t		total_len;
	size_t		len_str1;

	i = 0;
	len_str1 = ft_strlen(str1);
	len = len_str1 < size ? len_str1 : size;
	total_len = len + ft_strlen(str2);
	if (len == size)
		return (total_len);
	size = size - len - 1;
	while (str2[i] && i < size)
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (total_len);
}
