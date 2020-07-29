/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:32:05 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:14 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** TODO : The algorithm can probably be enhanced
*/

static void		fill(const char *str, char separator, char **result)
{
	int		start;
	size_t	pos;
	size_t	i;

	pos = 0;
	start = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator)
			if (i == 0 || str[i - 1] == separator)
				start = (int)i;
		if (start != -1 && (str[i + 1] == separator || str[i + 1] == '\0'))
		{
			result[pos] = ft_strsub(str, (unsigned int)start,
			i - (unsigned long)start + 1);
			start = -1;
			pos++;
		}
		i++;
	}
}

char			**ft_strsplit(const char *str, char separator)
{
	char	**result;
	size_t	count;
	size_t	i;

	if (!str)
		return (NULL);
	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator)
			if (i == 0 || str[i - 1] == separator)
				count++;
		i++;
	}
	if (!(result = malloc(sizeof(*result) * (unsigned long)count)))
		return (NULL);
	fill(str, separator, result);
	result[count - 1] = NULL;
	return (result);
}
