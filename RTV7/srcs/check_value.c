/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:03:47 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 14:45:47 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		check_tag_value(t_env *e, char **conf, int *j)
{
	check_tag(e, conf, *j);
	check_value(e, conf, *j);
	(*j)++;
}

void			check_objs(t_env *e, int j, int scl, int dif)
{
	int			pos;
	int			dir;
	int			clr;

	pos = 0;
	dir = 0;
	clr = 0;
	while (e->conf[j] && ft_strcmp(e->conf[j], "</obj>"))
	{
		if (!ft_strncmp(e->conf[j], "\t<pos>", 6))
			pos++;
		else if (!ft_strncmp(e->conf[j], "\t<dir>", 6))
			dir++;
		else if (!ft_strncmp(e->conf[j], "\t<scl>", 6))
			scl++;
		else if (!ft_strncmp(e->conf[j], "\t<dif>", 6))
			dif++;
		else if (!ft_strncmp(e->conf[j], "\t<clr>", 6))
			clr++;
		else
			free_env(e, "Error: <obj> syntax error\n");
		check_tag_value(e, e->conf, &j);
	}
	if (pos != 1 || dir != 1 || scl != 1 || clr != 1 || dif != 1 || !e->conf[j])
		free_env(e, "Error: <obj> syntax error\n");
}

static void		check_double(t_env *e, char **conf, int j, int *i)
{
	int			nb_dot;

	nb_dot = 0;
	if (conf[j][*i] == '-' || conf[j][*i] == '+')
		(*i)++;
	while (ft_isdigit(conf[j][*i]) || conf[j][*i] == '.')
	{
		if (conf[j][*i] == '.')
		{
			if (!ft_isdigit(conf[j][(*i) + 1]))
				free_env(e, "Error: value syntax error\n");
			if (nb_dot == 1)
				free_env(e, "Error: value syntax error\n");
			nb_dot++;
		}
		(*i)++;
	}
}

static void		check_doubles(t_env *e, char **conf, int j)
{
	int			nb_comma;
	int			i;

	nb_comma = 0;
	i = 6;
	if (!ft_isdigit(conf[j][i]) && conf[j][i] != '-' && conf[j][i] != '+')
		free_env(e, "Error: value syntax error\n");
	while (conf[j][i] != '<')
	{
		if (ft_isdigit(conf[j][i]) || conf[j][i] == '-' || conf[j][i] == '+')
			check_double(e, conf, j, &i);
		if ((conf[j][i] != ',' && conf[j][i] != '<') ||
				(conf[j][i] == '<' && nb_comma != 2) ||
				(conf[j][i] == ',' && !ft_isdigit(conf[j][i + 1]) &&
				(conf[j][i + 1] != '-' && conf[j][i + 1] != '+')))
			free_env(e, "Error: value syntax error\n");
		if (conf[j][i] == ',')
		{
			nb_comma++;
			i++;
		}
	}
}

void			check_value(t_env *e, char **conf, int j)
{
	int			i;
	int			k;

	i = 12;
	k = 6;
	if (!ft_strncmp(conf[j], "\t<pos>", 6))
		check_doubles(e, conf, j);
	else if (!ft_strncmp(conf[j], "\t<dir>", 6))
		check_doubles(e, conf, j);
	else if (!ft_strncmp(conf[j], "\t<scl>", 6))
		check_doubles(e, conf, j);
	else if (!ft_strncmp(conf[j], "\t<intensity>", 12))
		check_double(e, conf, j, &i);
	else if (!ft_strncmp(conf[j], "\t<dif>", 6))
		check_double(e, conf, j, &k);
	else if (!ft_strncmp(conf[j], "\t<clr>", 6))
		check_doubles(e, conf, j);
}
