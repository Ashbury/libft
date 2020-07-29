/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:34:07 by justasze          #+#    #+#             */
/*   Updated: 2018/06/13 20:53:14 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** TODO : It is ugly, make it better.
*/

char	*ft_strtrim(const char *input)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*output;

	i = 0;
	j = ft_strlen(input) - 1;
	while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		i++;
	if (!input[i])
		return ("");
	while (input[j] == ' ' || input[j] == '\n' || input[j] == '\t')
		j--;
	if ((output = ft_strnew(j - i + 1)))
	{
		k = 0;
		while (k < j - i + 1)
		{
			output[k] = input[i + k];
			k++;
		}
		output[k] = '\0';
		return (output);
	}
	return (NULL);
}
