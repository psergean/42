/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:49:46 by tzaaboul          #+#    #+#             */
/*   Updated: 2016/12/06 15:49:56 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_line(char *str, char **line)
{
	char		*eol;

	eol = ft_strchr(str, '\n');
	if (eol != NULL)
	{
		eol[0] = '\0';
		*line = ft_strdup(str);
		str = ft_strncpy(str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		str[0] = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str = NULL;
	char		*tmp;
	int			ret;

	if (!str)
		str = ft_strnew(0);
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || str == NULL)
		return (-1);
	while (ft_strchr(str, '\n') == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == -1)
			return (-1);
		else if (ret == 0)
			return (get_line(str, line));
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	return (get_line(str, line));
}
