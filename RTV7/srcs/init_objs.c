/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:02:42 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 20:39:09 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double		ft_div_nb(double nb, int dot, int is_neg)
{
	if (!dot && !is_neg)
		return (nb);
	else if (!dot && is_neg)
		return (-nb);
	while (dot)
	{
		dot--;
		nb /= 10;
	}
	if (is_neg)
		return (-nb);
	return (nb);
}

double				ft_atod(const char *nptr, int dot, int i)
{
	double			nb;
	int				is_neg;
	int				is_signed;

	nb = 0;
	is_neg = 0;
	is_signed = 0;
	if (nptr[i] == '-')
		is_neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		is_signed = 1;
		i++;
	}
	while (nptr[i] && (ft_isdigit(nptr[i]) || nptr[i] == '.'))
	{
		if (((nptr[0] == '-' || nptr[0] == '+') && i == 1) || i == 0)
			nb = nptr[i] - '0';
		else if (nptr[i] == '.')
			dot = ft_strlen(nptr) - i - 1;
		else
			nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (ft_div_nb(nb, dot, is_neg));
}

void				new_obj(t_env *e)
{
	t_obj			*tmp;

	tmp = e->obj;
	if (!e->obj)
	{
		e->obj = (t_obj *)ft_malloc(sizeof(*(e->obj)));
		e->obj->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_obj *)ft_malloc(sizeof(*(e->obj)));
		tmp->next->next = NULL;
	}
}

static void			init_color_scale(t_obj *obj, char **conf, int *i)
{
	unsigned int	s;

	s = 6;
	if (!ft_strncmp(conf[*i], "\t<scl>", 6))
	{
		obj->scale.x = get_val(conf[*i], s);
		s += (unsigned int)(val_len(conf[*i], s) + 1);
		obj->scale.y = get_val(conf[*i], s);
		s += (unsigned int)(val_len(conf[*i], s) + 1);
		obj->scale.z = get_val(conf[*i], s);
	}
	else if (!ft_strncmp(conf[*i], "\t<dif>", 6))
		obj->k = get_val(conf[*i], s);
	else if (!ft_strncmp(conf[*i], "\t<clr>", 6))
		get_color(&(obj->color), conf[*i]);
}

void				init_objs(t_obj *obj, char **conf, char *type, int *i)
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
		init_color_scale(obj, conf, i);
		(*i)++;
	}
}
