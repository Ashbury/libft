/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:23:31 by justasze          #+#    #+#             */
/*   Updated: 2018/10/13 12:38:54 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		search_eol(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		read_until_eol_or_eof(const int fd, char **remain)
{
	char	*tmp;
	char	buffer[GNL_BUFF_SIZE + 1];
	ssize_t	ret;

	while ((ret = read(fd, buffer, GNL_BUFF_SIZE - 1)) != 0)
	{
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (*remain)
		{
			if (!(tmp = ft_strjoin(*remain, buffer)))
				return (-1);
			free(*remain);
			if (!(*remain = ft_strdup(tmp)))
				return (-1);
			free(tmp);
		}
		else if (!(*remain = ft_strdup(buffer)))
			return (-1);
		if (search_eol(*remain) != -1)
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*remain;
	char			*tmp;
	int				ret;

	if (fd < 0 || fd > 255 || line == NULL)
		return (-1);
	if (remain && (ret = search_eol(remain)) != -1)
	{
		if (!(*line = ft_strndup(remain, (size_t)ret))
			|| !(tmp = ft_strdup(remain + ret + 1)))
			return (-1);
		free(remain);
		if (!(remain = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	if ((ret = read_until_eol_or_eof(fd, &remain)) != 0)
		return (ret == -1 ? -1 : get_next_line(fd, line));
	if (remain && ft_strcmp(remain, "") && (*line = remain))
	{
		ft_strdel(&remain);
		return (1);
	}
	return (0);
}
