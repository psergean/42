/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:24:21 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/30 13:40:41 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			init_cam(t_env *e, char **conf, int *i)
{
	unsigned int	s;

	e->cam = (t_cam *)ft_malloc(sizeof(*(e->cam)));
	while (ft_strcmp(conf[*i], "</cam>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			e->cam->pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam->pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam->pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<dir>", 6))
		{
			e->cam->dir.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam->dir.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			e->cam->dir.z = get_val(conf[*i], s);
		}
		(*i)++;
	}
}

static void			init_light(t_env *e, char **conf, int *i)
{
	unsigned int	s;

	e->light = (t_light *)ft_malloc(sizeof(*(e->light)));
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
		(*i)++;
	}
}

static void			new_obj(t_env *e)
{
	t_obj			*tmp;

	tmp = e->obj;
	if (!e->obj)
	{
		e->obj = (t_obj *)ft_malloc(sizeof(*(e->obj)));
		e->obj->next = NULL;
		e->obj->id = 0;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_obj *)ft_malloc(sizeof(*(e->obj)));
		tmp->next->next = NULL;
		tmp->next->id = tmp->id + 1;
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
		init_sphere(new, conf, 6, i);
	else if (!ft_strncmp(conf[*i] + 7, "plane", 5))
		init_plane(new, conf, 6, i);
	else if (!ft_strncmp(conf[*i] + 7, "cylinder", 8))
		init_cyl_cone(new, conf, "cylinder", i);
	else if (!ft_strncmp(conf[*i] + 7, "cone", 4))
		init_cyl_cone(new, conf, "cone", i);
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
}
