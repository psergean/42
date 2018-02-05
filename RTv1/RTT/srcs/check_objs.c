/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:15:02 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/12 10:03:58 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			check_sphere(t_env *e, char **conf, int j, int pos)
{
	int			radius;
	int			color;

	radius = 0;
	color = 0;
	while (conf[j] && ft_strcmp(conf[j], "</obj>"))
	{
		if (ft_strncmp(conf[j], "\t<pos>", 6) &&
				ft_strncmp(conf[j], "\t<radius>", 9) &&
				ft_strncmp(conf[j], "\t<color>", 8))
			free_env(e, "Error: <sphere> syntax error\n");
		if (!ft_strncmp(conf[j], "\t<pos>", 6))
			pos++;
		else if (!ft_strncmp(conf[j], "\t<radius>", 9))
			radius++;
		else if (!ft_strncmp(conf[j], "\t<color>", 8))
			color++;
		check_tag(e, conf, j);
		check_value(e, conf, j);
		j++;
	}
	if (pos != 1 || radius != 1 || color != 1)
		free_env(e, "Error: <sphere> syntax error\n");
	else if (!conf[j])
		free_env(e, "Error: <sphere> syntax error\n");
}

void			check_plane(t_env *e, char **conf, int j, int pos)
{
	int			dir;
	int			color;

	dir = 0;
	color = 0;
	while (conf[j] && ft_strcmp(conf[j], "</obj>"))
	{
		if (ft_strncmp(conf[j], "\t<pos>", 6) &&
				ft_strncmp(conf[j], "\t<dir>", 6) &&
				ft_strncmp(conf[j], "\t<color>", 8))
			free_env(e, "Error: <plane> syntax error\n");
		if (!ft_strncmp(conf[j], "\t<pos>", 6))
			pos++;
		else if (!ft_strncmp(conf[j], "\t<dir>", 6))
			dir++;
		else if (!ft_strncmp(conf[j], "\t<color>", 8))
			color++;
		check_tag(e, conf, j);
		check_value(e, conf, j);
		j++;
	}
	if (pos != 1 || dir != 1 || color != 1)
		free_env(e, "Error: <plane> syntax error\n");
	else if (!conf[j])
		free_env(e, "Error: conf_file syntax error\n");
}

static void		check_tag_value(t_env *e, char **conf, int *j)
{
	check_tag(e, conf, *j);
	check_value(e, conf, *j);
	(*j)++;
}

void			check_cyl_cone(t_env *e, int j, int pos, int dir)
{
	int			h;
	int			r;
	int			color;

	h = 0;
	r = 0;
	color = 0;
	while (e->conf[j] && ft_strcmp(e->conf[j], "</obj>"))
	{
		if (!ft_strncmp(e->conf[j], "\t<pos>", 6))
			pos++;
		else if (!ft_strncmp(e->conf[j], "\t<dir>", 6))
			dir++;
		else if (!ft_strncmp(e->conf[j], "\t<height>", 9))
			h++;
		else if (!ft_strncmp(e->conf[j], "\t<radius>", 9))
			r++;
		else if (!ft_strncmp(e->conf[j], "\t<color>", 8))
			color++;
		else
			free_env(e, "Error: <obj> syntax error\n");
		check_tag_value(e, e->conf, &j);
	}
	if (pos != 1 || dir != 1 || h != 1 || r != 1 || color != 1 || !e->conf[j])
		free_env(e, "Error: <obj> syntax error\n");
}
