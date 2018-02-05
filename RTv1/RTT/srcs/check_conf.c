/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:39:27 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/12 11:13:59 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			check_tag(t_env *e, char **conf, int j)
{
	if (!ft_strncmp(conf[j], "\t<pos>", 6) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 6, "</pos>"))
		free_env(e, "Error: <pos> syntax error\n");
	else if (!ft_strncmp(conf[j], "\t<dir>", 6) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 6, "</dir>"))
		free_env(e, "Error: <dir> syntax error\n");
	else if (!ft_strncmp(conf[j], "\t<type>", 7) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 7, "</type>"))
		free_env(e, "Error: <type> syntax error\n");
	else if (!ft_strncmp(conf[j], "\t<radius>", 9) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 9, "</radius>"))
		free_env(e, "Error: <radius> syntax error\n");
	else if (!ft_strncmp(conf[j], "\t<height>", 9) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 9, "</height>"))
		free_env(e, "Error: <height> syntax error\n");
	else if (!ft_strncmp(conf[j], "\t<color>", 8) &&
			ft_strcmp(conf[j] + ft_strlen(conf[j]) - 8, "</color>"))
		free_env(e, "Error: <color> syntax error\n");
}

static void		check_cam(t_env *e, char **conf, int j)
{
	int			pos;
	int			dir;

	pos = 0;
	dir = 0;
	while (conf[j] && ft_strcmp(conf[j], "</cam>"))
	{
		if (ft_strncmp(conf[j], "\t<pos>", 6) &&
				ft_strncmp(conf[j], "\t<dir>", 6))
			free_env(e, "Error <cam> syntax error\n");
		if (!ft_strncmp(conf[j], "\t<pos>", 6))
			pos++;
		else if (!ft_strncmp(conf[j], "\t<dir>", 6))
			dir++;
		check_tag(e, conf, j);
		check_value(e, conf, j);
		j++;
	}
	if (pos != 1 || dir != 1)
		free_env(e, "Error: <cam> syntax error\n");
	else if (!conf[j])
		free_env(e, "Error: conf_file syntax error\n");
}

static void		check_light(t_env *e, char **conf, int j)
{
	int			pos;

	pos = 0;
	while (conf[j] && ft_strcmp(conf[j], "</light>"))
	{
		if (ft_strncmp(conf[j], "\t<pos>", 6))
			free_env(e, "Error: <light> syntax error\n");
		if (!ft_strncmp(conf[j], "\t<pos>", 6))
			pos++;
		check_tag(e, conf, j);
		check_value(e, conf, j);
		j++;
	}
	if (pos != 1)
		free_env(e, "Error: <light> syntax error\n");
	else if (!conf[j])
		free_env(e, "Error: conf_file syntax error\n");
}

static void		check_obj(t_env *e, char **conf, int j)
{
	if (ft_strncmp(conf[j], "\t<type>", 7))
		free_env(e, "Error: <obj> syntax error\n");
	check_tag(e, conf, j);
	if (!ft_strncmp(conf[j] + 7, "sphere", 6))
		check_sphere(e, conf, j + 1, 0);
	else if (!ft_strncmp(conf[j] + 7, "plane", 5))
		check_plane(e, conf, j + 1, 0);
	else if (!ft_strncmp(conf[j] + 7, "cylinder", 8) ||
			!ft_strncmp(conf[j] + 7, "cone", 4))
		check_cyl_cone(e, j + 1, 0, 0);
	else
		free_env(e, "Error: <type> syntax error\n");
}

void			check_conf(t_env *e, char **conf, int i)
{
	int			cam;

	cam = 0;
	while (conf[i])
	{
		if (ft_strcmp(conf[i], "<cam>") && ft_strcmp(conf[i], "<obj>") &&
				ft_strcmp(conf[i], "<light>"))
			free_env(e, "Error: conf_file syntax error\n");
		if (!ft_strcmp(conf[i], "<cam>"))
		{
			if (cam == 1)
				free_env(e, "Error: too many <cam>\n");
			check_cam(e, conf, i + 1);
			cam++;
		}
		else if (!ft_strcmp(conf[i], "<light>"))
			check_light(e, conf, i + 1);
		else if (!ft_strcmp(conf[i], "<obj>"))
			check_obj(e, conf, i + 1);
		while (ft_strncmp(conf[i], "</", 2))
			i++;
		i++;
	}
	if (!cam)
		free_env(e, "Error: no <cam> in conf_file\n");
}
