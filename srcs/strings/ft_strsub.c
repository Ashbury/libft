/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:17:35 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:14 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (str == NULL || len == 0)
		return (ft_strnew(0));
	if (len && ft_strlen(str) >= len && (ret = ft_strnew(len)))
	{
		while (i < len && str[i])
		{
			ret[i] = str[start + i];
			i++;
		}
		ret[len] = '\0';
		return (ret);
	}
	return (NULL);
}
