/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   establish_connexion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maven <maven@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:54:25 by maven             #+#    #+#             */
/*   Updated: 2019/07/03 12:57:48 by maven            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions attempt to connect to a server, assigns the socket to a
** pointer arguments, and return 0 if the connexion failed or 1.
**
** The service and hints arguments might be NULL. Service will usually be
** the port you want.
**
** On Linux, the first element of the server_infos list will likely be TCP
** by default, so hints are usually not needed.
**
** On OSX, the defaults appears to be UDP, so you might want to use
** the hints to get TCP.
**
** This is compatible with both IPv4 and IPv6.
*/
int	establish_connexion(int *sock, char *server, char *service,
		struct addrinfo *hints)
{
	struct addrinfo	*server_infos;

	if (getaddrinfo(server, service, hints, &server_infos) == -1
			|| server_infos == NULL)
	{
		perror("getaddrinfo: ");
		return (0);
	}
	*sock = socket(server_infos->ai_family, server_infos->ai_socktype,
			server_infos->ai_protocol);
	if (*sock == -1)
	{
		freeaddrinfo(server_infos);
		perror("socket: ");
		return (0);
	}
	if (connect(*sock, server_infos->ai_addr, server_infos->ai_addrlen) < 0)
	{
		perror("connect: ");
		freeaddrinfo(server_infos);
		close(*sock);
		return (0);
	}
	freeaddrinfo(server_infos);
	return (1);
}
