/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:05 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/03 11:36:44 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*s[4096];
	char			*tmp;
	int				nbr;
	
	if (fd < 0 || line == 0)
		return (-1);
	while ((nbr = read(fd, buff, BUFF_SIZE)) > 0);
	{
		
	}
	return (nbr);
}
