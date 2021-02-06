/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:46:43 by justasze          #+#    #+#             */
/*   Updated: 2018/09/27 16:50:23 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnchr(char *str, int c, unsigned int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			n--;
			if (n == 0)
				break ;
		}
		i++;
	}
	return (&str[i]);
}
