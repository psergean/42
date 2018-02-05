/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:02:42 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/24 22:03:10 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			set_uninit(t_obj *obj, char *type)
{
	if (!ft_strcmp(type, "sphere"))
	{
		obj->dir.x = 0;
		obj->dir.y = 0;
		obj->dir.z = 0;
		obj->h = 0;
	}
	else if (!ft_strcmp(type, "plane"))
	{
		obj->rad = 0;
		obj->h = 0;
	}
}

void				init_sphere(t_obj *sp, char **conf, unsigned int s, int *i)
{
	sp->type = ft_strdup("sphere");
	while (ft_strcmp(conf[*i], "</obj>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			sp->pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			sp->pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			sp->pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<radius>", 9))
			sp->rad = get_val(conf[*i], 9);
		else if (!ft_strncmp(conf[*i], "\t<color>", 8))
			get_color(sp, conf[*i]);
		(*i)++;
	}
	set_uninit(sp, sp->type);
}

void				init_plane(t_obj *pl, char **conf, unsigned int s, int *i)
{
	pl->type = ft_strdup("plane");
	while (ft_strcmp(conf[*i], "</obj>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			pl->pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			pl->pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			pl->pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<dir>", 6))
		{
			pl->dir.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			pl->dir.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			pl->dir.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<color>", 8))
			get_color(pl, conf[*i]);
		(*i)++;
	}
	set_uninit(pl, pl->type);
}

static void			init_h_rad(t_obj *obj, char **conf, int *i)
{
	if (!ft_strncmp(conf[*i], "\t<radius>", 9))
		obj->rad = get_val(conf[*i], 9);
	else if (!ft_strncmp(conf[*i], "\t<height>", 9))
		obj->h = get_val(conf[*i], 9);
	else if (!ft_strncmp(conf[*i], "\t<color>", 8))
		get_color(obj, conf[*i]);
}

void				init_cyl_cone(t_obj *obj, char **conf, char *type, int *i)
{
	unsigned int	s;

	obj->type = ft_strdup(type);
	while (ft_strcmp(conf[*i], "</obj>"))
	{
		s = 6;
		if (!ft_strncmp(conf[*i], "\t<pos>", 6))
		{
			obj->pos.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			obj->pos.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			obj->pos.z = get_val(conf[*i], s);
		}
		else if (!ft_strncmp(conf[*i], "\t<dir>", 6))
		{
			obj->dir.x = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			obj->dir.y = get_val(conf[*i], s);
			s += (unsigned int)(val_len(conf[*i], s) + 1);
			obj->dir.z = get_val(conf[*i], s);
		}
		init_h_rad(obj, conf, i);
		(*i)++;
	}
}
