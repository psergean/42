/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2017/07/20 14:59:09 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

static t_file	*newf(int fd, t_file *begin)
{
	if (!(begin = (t_file*)malloc(sizeof(*begin))))
		return (NULL);
	begin->str = ft_strnew(0);
	begin->fd = fd;
	return (begin);
}

static int		get_str(t_file *begin, char **line)
{
	char	*eol;

	eol = ft_strchr(begin->str, '\n');
	if (eol)
	{
		eol[0] = '\0';
		*line = ft_strdup(begin->str);
		begin->str = ft_strncpy(begin->str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(begin->str) > 0)
	{
		*line = ft_strdup(begin->str);
		*begin->str = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*begin = NULL;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp_str;

	if (!begin)
	{
		begin = newf(fd, begin);
	}
	if (begin->fd < 0 || !(begin->str) || !line || BUFF_SIZE <= 0)
		return (-1);
	while (!ft_strchr(begin->str, '\n'))
	{
		if ((ret = read(begin->fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret == 0)
			return (get_str(begin, line));
		tmp_str = ft_strjoin(begin->str, buff);
		free(begin->str);
		begin->str = tmp_str;
	}
	return (get_str(begin, line));
}
