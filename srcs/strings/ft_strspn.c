/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:36:31 by Ashbury           #+#    #+#             */
/*   Updated: 2018/06/13 20:46:43 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(char *str1, char *str2)
{
	size_t ret;

	ret = 0;
	while (*str1 && ft_strchr(str2, *str1++))
		ret++;
	return (ret);
}
