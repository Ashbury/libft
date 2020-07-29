/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:13:16 by Ashbury           #+#    #+#             */
/*   Updated: 2018/06/13 20:49:05 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *str1, char *str2)
{
	size_t ret;

	ret = 0;
	while (*str1)
	{
		if (ft_strchr(str2, *str1))
			return (ret);
		else
		{
			str1++;
			ret++;
		}
	}
	return (ret);
}
