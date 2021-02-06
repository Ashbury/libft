/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:27:36 by justasze          #+#    #+#             */
/*   Updated: 2018/07/06 04:22:53 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_signed_width(ssize_t nbr, ssize_t base)
{
	size_t	ret;

	ret = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		ret++;
	}
	while (nbr /= base)
		ret++;
	return (ret);
}
