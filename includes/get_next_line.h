/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:31:06 by justasze          #+#    #+#             */
/*   Updated: 2018/10/13 12:38:13 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H

# define FT_GET_NEXT_LINE_H
# define GNL_BUFF_SIZE 4096
# include "libft.h"

int		get_next_line(int const fd, char **line);

#endif
