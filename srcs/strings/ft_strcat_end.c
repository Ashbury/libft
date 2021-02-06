/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:00:33 by justasze          #+#    #+#             */
/*   Updated: 2018/10/19 14:02:31 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This is an optimised version of strcat. It returns a pointer on the last
** character of the string to for further concatenations.
** Thank you Joel Spolsky.
*/

char	*ft_strcat_end(char *str1, const char *str2)
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
	return (str1 + len + i);
}
