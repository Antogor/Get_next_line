/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:25:13 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/11 10:16:15 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total;
	int		l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ((ft_strlen(s1)) + (ft_strlen(s2)) + 1);
	new = (char*)malloc(sizeof(char) * total);
	if (new == 0)
		return (NULL);
	l = 0;
	while (total > 0)
	{
		if (*s1 != '\0')
			new[l++] = *s1++;
		if (*s1 == '\0')
		{
			while (*s2 != '\0')
				new[l++] = *s2++;
			break ;
		}
		total--;
	}
	new[l] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			q;

	if (s == 0)
		return (NULL);
	substr = (char*)malloc(len + 1);
	if (substr == 0)
		return (NULL);
	q = 0;
	if (start > ft_strlen(s))
	{
		substr[q] = '\0';
		return (substr);
	}
	while (q < len)
		substr[q++] = s[start++];
	substr[q] = '\0';
	return (substr);
}
