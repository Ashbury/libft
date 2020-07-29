/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:58:53 by justasze          #+#    #+#             */
/*   Updated: 2016/07/17 18:06:47 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_n_free(int n, ...)
{
	va_list ap;
	int		i;

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		free(va_arg(ap, char *));
		i++;
	}
}
