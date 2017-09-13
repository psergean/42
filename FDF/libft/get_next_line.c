/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2016/11/18 17:25:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		get_str(char *str, char **line)
{
	char	*eol;

	eol = ft_strchr(str, '\n');
	if (eol)
	{
		eol[0] = '\0';
		*line = ft_strdup(str);
		str = ft_strncpy(str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp_str;

	if (!str)
	{
		str = ft_strnew(0);
	}
	if (fd < 0 || !str || !line || BUFF_SIZE <= 0)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (get_str(str, line));
		buff[ret] = '\0';
		tmp_str = ft_strjoin(str, buff);
		free(str);
		str = tmp_str;
	}
	return (get_str(str, line));
}
