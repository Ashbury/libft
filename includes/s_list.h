/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 19:50:19 by justasze          #+#    #+#             */
/*   Updated: 2016/05/05 19:52:04 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_H

# define S_LIST_H

# include "libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
