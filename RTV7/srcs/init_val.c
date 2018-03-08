/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:24:21 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 19:49:27 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			init_cam(t_env *e, char **conf, int *i)
{
	unsigned int	s;

	while (ft_strcmp(conf[*i], "</cam>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			e->cam.pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam.pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam.pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<dir>", 6))
		{
			e->cam.dir.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam.dir.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam.dir.z = get_val(conf[*i], s);
		}
		(*i)++;
	}
}

static void			new_light(t_env *e)
{
	t_light			*tmp;

	tmp = e->light;
	if (!e->light)
	{
		e->light = (t_light *)ft_malloc(sizeof(*(e->light)));
		e->light->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_light *)ft_malloc(sizeof(*(e->light)));
		tmp->next->next = NULL;
	}
}

static void			init_light(t_env *e, char **conf, int *i)
{
	t_light			*new;
	unsigned int	s;

	new_light(e);
	new = e->light;
	while (new->next)
		new = new->next;
	while (ft_strcmp(conf[*i], "</light>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			e->light->pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->light->pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->light->pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<clr>", 6))
			get_color(&(new->color), conf[*i]);
		else if (!ft_strncmp(conf[*i], "\t<intensity>", 12))
			new->i = get_val(conf[*i], 12);
		(*i)++;
	}
}

static void			init_obj(t_env *e, char **conf, int *i)
{
	t_obj			*new;

	new_obj(e);
	new = e->obj;
	while (new->next)
		new = new->next;
	(*i)++;
	if (!ft_strncmp(conf[*i] + 7, "sphere", 6))
		init_objs(new, conf, "sphere", i);
	else if (!ft_strncmp(conf[*i] + 7, "plane", 5))
		init_objs(new, conf, "plane", i);
	else if (!ft_strncmp(conf[*i] + 7, "cylinder", 8))
		init_objs(new, conf, "cylinder", i);
	else if (!ft_strncmp(conf[*i] + 7, "cone", 4))
		init_objs(new, conf, "cone", i);
}

void				init_val(t_env *e, char *file)
{
	int				i;

	i = 0;
	get_conf(e, file);
	if (!e->conf[0])
		free_env(e, "Error: empty conf_file\n");
	check_conf(e, e->conf, 0);
	while (e->conf[i])
	{
		if (!ft_strcmp(e->conf[i], "<cam>"))
			init_cam(e, e->conf, &i);
		else if (!ft_strcmp(e->conf[i], "<light>"))
			init_light(e, e->conf, &i);
		else if (!ft_strcmp(e->conf[i], "<obj>"))
			init_obj(e, e->conf, &i);
		i++;
	}
	ft_free_tab(e->conf);
	e->conf = NULL;
	check_short_double(e);
}
