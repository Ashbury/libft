/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_memory_logs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:05:55 by justasze          #+#    #+#             */
/*   Updated: 2018/06/17 19:45:56 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MEMORY_LOGS_H

# define S_MEMORY_LOGS_H

# include "ft_malloc.h"

typedef struct	s_memory_logs
{
	size_t		mapped_bytes;
	size_t		used_bytes;
	size_t		unused_bytes;
	size_t		advanced_logs;
}				t_memory_logs;

#endif
