/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:25:13 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/03 13:15:09 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int l;

	l = 0;
	while (s[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	x;
	size_t	l;

	x = ft_strlen(s1);
	l = 0;
	dup = (char*)malloc(sizeof(char) * (x + 1));
	if (dup == 0)
		return (NULL);
	while (s1[l] != '\0')
	{
		dup[l] = s1[l];
		l++;
	}
	dup[l] = '\0';
	return ((char*)dup);
}
