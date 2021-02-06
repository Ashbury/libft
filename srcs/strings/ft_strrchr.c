/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 05:14:54 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:44:44 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (!c)
		return (&str[i]);
	while (str[--i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}
