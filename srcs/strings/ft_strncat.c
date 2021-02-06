/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 02:40:46 by justasze          #+#    #+#             */
/*   Updated: 2016/05/05 19:34:03 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str1);
	while (i < n)
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (str1);
}
