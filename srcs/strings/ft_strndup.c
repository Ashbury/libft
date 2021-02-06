/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:24:29 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:50:25 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while ((str[i]) && (i < n))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
