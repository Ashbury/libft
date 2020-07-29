/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:33:12 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:14 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char *str, const char *src, size_t *pos)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		str[*pos] = src[i];
		i++;
		*pos += 1;
	}
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		fill(str, s1, &i);
		fill(str, s2, &i);
		return (str);
	}
	return (NULL);
}
