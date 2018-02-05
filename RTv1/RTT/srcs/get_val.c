/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:46:34 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/22 22:57:34 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		ft_hexatoi(char *hexa)
{
	int			c;

	if (hexa[0] >= 'A' && hexa[0] <= 'F')
		c = (hexa[0] - 55) * 16;
	else if (hexa[0] >= 'a')
		c = (hexa[0] - 87) * 16;
	else
		c = (hexa[0] - '0') * 16;
	if (hexa[1] >= 'A' && hexa[1] <= 'F')
		c += (hexa[1] - 55);
	else if (hexa[1] >= 'a')
		c += (hexa[1] - 87);
	else
		c += (hexa[1] - '0');
	free(hexa);
	return (c);
}

void			get_color(t_obj *obj, char *line)
{
	obj->color.r = ft_hexatoi(ft_strsub(line, 10, 2));
	obj->color.g = ft_hexatoi(ft_strsub(line, 15, 2));
	obj->color.b = ft_hexatoi(ft_strsub(line, 20, 2));
}

size_t			val_len(char *line, unsigned int s)
{
	size_t		len;

	len = 0;
	while (line[s] != ',' && line[s] != '<')
	{
		len++;
		s++;
	}
	return (len);
}

double			get_val(char *line, unsigned int s)
{
	char		*sub;
	double		nb;

	sub = ft_strsub(line, s, val_len(line, s));
	nb = ft_atod(sub, 0, 0);
	free(sub);
	return (nb);
}

void			get_conf(t_env *e, char *file)
{
	int			fd;
	int			ret;
	char		*rd;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

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
