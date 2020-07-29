/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_page.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:38:28 by justasze          #+#    #+#             */
/*   Updated: 2017/11/28 16:59:50 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PAGE_H

# define S_PAGE_H

typedef struct		s_page
{
	size_t			is_used;
	size_t			size;
	struct s_page	*next;
}					t_page;

#endif
