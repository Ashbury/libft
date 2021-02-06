/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:07:34 by Ashbury           #+#    #+#             */
/*   Updated: 2018/04/20 11:26:45 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char *delim)
{
	static char *remains = NULL;

	if (str)
		remains = str;
	else if (!remains)
		return (0);
	str = remains + ft_strspn(remains, delim);
	remains = str + ft_strcspn(str, delim);
	if (remains == str)
		return (remains = 0);
	if (*remains)
	{
		*remains = '\0';
		remains = remains + 1;
	}
	else
		remains = NULL;
	return (str);
}
