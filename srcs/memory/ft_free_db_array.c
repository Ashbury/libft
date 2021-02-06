/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_db_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:07:32 by justasze          #+#    #+#             */
/*   Updated: 2016/08/16 13:56:21 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_db_array(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}
