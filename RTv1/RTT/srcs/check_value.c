/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:03:47 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/12 19:23:14 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		check_hexa(t_env *e, char **conf, int j, int *i)
{
	if (conf[j][*i] != '0')
		free_env(e, "Error: <color> value syntax error\n");
	else if (conf[j][(*i) + 1] != 'x')
		free_env(e, "Error: <color> value syntax error\n");
	else if (!ft_isdigit(conf[j][(*i) + 2]) &&
			!(conf[j][(*i) + 2] >= 'A' && conf[j][(*i) + 2] <= 'F') &&
			!(conf[j][(*i) + 2] >= 'a' && conf[j][(*i) + 2] <= 'f'))
		free_env(e, "Error: <color> value syntax error\n");
	else if (!ft_isdigit(conf[j][(*i) + 3]) &&
			!(conf[j][(*i) + 3] >= 'A' && conf[j][(*i) + 3] <= 'F') &&
			!(conf[j][(*i) + 3] >= 'a' && conf[j][(*i) + 3] <= 'f'))
		free_env(e, "Error: <color> value syntax error\n");
	(*i) += 4;
}

static void		check_color(t_env *e, char **conf, int j)
{
	int			nb_comma;
	int			i;

	nb_comma = 0;
	i = 8;
	if (conf[j][i] != '0' && conf[j][i + 1] != 'x')
		free_env(e, "Error: <color> value syntax error\n");
	while (conf[j][i] != '<')
	{
		if (conf[j][i] == '0')
			check_hexa(e, conf, j, &i);
		if ((conf[j][i] != ',' && conf[j][i] != '<') ||
				(conf[j][i] == '<' && nb_comma != 2) ||
				(conf[j][i] == ',' && conf[j][i + 1] != '0'))
			free_env(e, "Error: <color> value syntax error\n");
		if (conf[j][i] == ',')
		{
			nb_comma++;
			i++;
		}
	}
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

	i = 9;
	if (!ft_strncmp(conf[j], "\t<pos>", 6) ||
			!ft_strncmp(conf[j], "\t<dir>", 6))
		check_doubles(e, conf, j);
	else if (!ft_strncmp(conf[j], "\t<radius>", 9))
		check_double(e, conf, j, &i);
	else if (!ft_strncmp(conf[j], "\t<height>", 9))
		check_double(e, conf, j, &i);
	else if (!ft_strncmp(conf[j], "\t<color>", 8))
		check_color(e, conf, j);
}
