/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maven <maven@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:24:04 by justasze          #+#    #+#             */
/*   Updated: 2019/07/03 12:56:03 by maven            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <arpa/inet.h>
# include <limits.h>
# include <netdb.h>
# include <netinet/in.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <wchar.h>

# include "s_list.h"
# include "prototypes.h"
# include "get_next_line.h"
# include "ft_malloc.h"
# include "ft_printf.h"

# define BUFFER_SIZE 4096
# define QUOTE_ME(x) #x
# define STR(x) QUOTE_ME(x)

#endif
