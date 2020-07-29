/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:42:31 by justasze          #+#    #+#             */
/*   Updated: 2016/08/13 17:39:09 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	if ((dup = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}
