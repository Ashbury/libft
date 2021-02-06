/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ashbury <Ashbury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:57:31 by justasze          #+#    #+#             */
/*   Updated: 2018/06/17 19:46:54 by Ashbury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# include "libft.h"
# include "s_page.h"
# include "s_mapped_zone.h"
# include "s_memory_logs.h"

# define ALIGNMENT 8
# define TINY_CAP 1696
# define TINY_ZONE_SIZE 42
# define SMALL_CAP 4768
# define SMALL_ZONE_SIZE 117
# define HEX_BASE "0123456789ABCDEF"

extern t_mapped_zone	*g_zones;
extern pthread_mutex_t	g_mutex;

void			*ft_malloc(size_t size);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			*ft_reallocf(void *ptr, size_t size);
void			ft_free(void *ptr);
void			*ft_realloc(void *ptr, size_t size);
void			*get_page(size_t size);
void			add_zone(size_t size, void **ret);
void			show_alloc_mem(void);
void			end_free(void) __attribute__((destructor));
void			pre_mapper(void) __attribute__((constructor));
void			ft_put_addr(size_t value, size_t end_of_line);
void			ft_put_size_t(size_t value);
size_t			align(size_t alignment, size_t size);
t_mapped_zone	*ft_find_zone(void *ptr);
t_page			*ft_find_page(t_mapped_zone *zone, void *ptr);

#endif
