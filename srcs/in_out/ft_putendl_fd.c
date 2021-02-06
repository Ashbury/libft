/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:10:58 by justasze          #+#    #+#             */
/*   Updated: 2015/11/30 15:51:38 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
