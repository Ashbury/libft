/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 00:41:56 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:31:01 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i])
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (str1);
}
