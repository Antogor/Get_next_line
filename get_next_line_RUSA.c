/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:42:41 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/06 19:32:54 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static int	ft_comp_new_line(char **s, char **line)
{
	int		l;
	char	*tmp;

	l = 0;
	while ((*s)[l] != '\n' && (*s)[l] != '\0')
		l++;
	if ((*s)[l] == '\n')
	{
		*line = ft_substr(*s, 0, l);
		tmp = ft_strdup(&(*s)[l + 1]);
		free(*s);
		*s = tmp;
	}
	else if ((*s)[l] == '\0')
	{
		*line = ft_strdup(*s);
		free(*s);
		return (0);
	}
	return (1);
}*/

/*static int	ft_comp(int bwr, int fd, char **s, char **line)
{
	if (bwr < 0)
		return (-1);
	else if (bwr == 0 && s[fd] == NULL)
	{
		*line = ft_strdup(*s);
		free(*s);
		return (0);
	}
	else
		return (ft_comp_new_line(&s[fd], line));
}*/

/*char 		*check_rem(char *rem, char **line)
{
	char *p_n;

	p_n = NULL;
	if (rem)
	{
		if ((p_n = ft_strchr(rem, '\n')))
		{
			p_n = '\0';
			*line = ft_strdup(rem);
			ft_memcpy(rem, ++p_n, ft_strlen(p_n));
		}
		else
		{
			*line = ft_strdup(rem);
			free (rem);
		}
		
	}
	else
		ft_bzero(*line, 1);
}*/

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	//static char *s[4096];
	static char	*rem;
	//char		*tmp;
	char		*p_n;
	int			bwr;
	int			flag;

	if (fd < 0 || line == 0)
		return (-1);
	flag = 1;
	if (rem)
		*line = ft_strdup(rem);
	else
		ft_bzero(*line, 1);
	while (flag && (bwr = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bwr] = '\0';
		if ((p_n = ft_strchr(buff, '\n')))
		{
			*p_n = '\0';
			flag = 0;
			p_n++;
			rem = ft_strdup (p_n);
		}
		*line = ft_strjoin(*line, buff);
		/*if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}*/
	}
	//return (ft_comp(bwr, fd, s, line));
	return (0);
}
