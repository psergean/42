/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:46:34 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 20:17:31 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				get_color(t_color *color, char *line)
{
	unsigned int	s;

	s = 6;
	color->r = get_val(line, s);
	s += (unsigned int)(val_len(line , s) + 1);
	color->g = get_val(line, s);
	s += (unsigned int)(val_len(line , s) + 1);
	color->b = get_val(line, s);
}

size_t				val_len(char *line, unsigned int s)
{
	size_t			len;

	len = 0;
	while (line[s] != ',' && line[s] != '<')
	{
		len++;
		s++;
	}
	return (len);
}

double				get_val(char *line, unsigned int s)
{
	char			*sub;
	double			nb;

	sub = ft_strsub(line, s, val_len(line, s));
	nb = ft_atod(sub, 0, 0);
	free(sub);
	return (nb);
}

void				get_conf(t_env *e, char *file)
{
	int				fd;
	int				ret;
	char			*rd;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	fd = ft_open(file, O_RDONLY);
	ret = ft_read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	rd = ft_strdup(buf);
	while ((ret = ft_read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(rd, buf);
		free(rd);
		rd = tmp;
	}
	e->conf = ft_strsplit(rd, '\n');
	free(rd);
}
