/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:54:00 by justasze          #+#    #+#             */
/*   Updated: 2018/10/04 14:54:44 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Basic function to clean list element.
*/

void	clean_elem(void *content, size_t size)
{
	free(content);
	(void)size;
}
