/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:05:01 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:14 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
