/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mapped_zone.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:38:19 by justasze          #+#    #+#             */
/*   Updated: 2017/12/06 04:46:14 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAPPED_ZONE_H

# define S_MAPPED_ZONE_H

# include "ft_malloc.h"

typedef struct				s_mapped_zone
{
	size_t					size;
	size_t					used_size;
	t_page					*pages;
	struct s_mapped_zone	*next;
}							t_mapped_zone;

#endif
