/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:51:03 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 20:50:17 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			check_short_double(t_env *e)
{
	t_obj		*tmp1;
	t_light		*tmp2;

	tmp1 = e->obj;
	tmp2 = e->light;
	printf("k=%f r=%f g=%f b=%f\n", tmp1->k, tmp1->color.r, tmp1->color.g, tmp1->color.b);
	while (tmp1)
	{
		if (tmp1->k < 0 || tmp1->k > 1 || tmp1->color.r < 0 ||
				tmp1->color.r > 1 || tmp1->color.g < 0 ||
				tmp1->color.g > 1 || tmp1->color.b < 0 ||
				tmp1->color.b > 1)
			free_env(e, "Error: [i | k | r | g | b] must be between 0 & 1\n");
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		if (tmp2->i < 0 || tmp2->i > 1 || tmp2->color.r < 0 ||
				tmp2->color.r > 1 || tmp2->color.g < 0 ||
				tmp2->color.g > 1 || tmp2->color.b < 0 ||
				tmp2->color.b > 1)
			free_env(e, "Error: [i | k | r | g | b] must be between 0 & 1\n");
		tmp2 = tmp2->next;
	}
}

static void		free_obj(t_obj *obj)
{
	t_obj		*tmp;

	tmp = obj;
	while (obj)
	{
		tmp = obj->next;
		free(obj->type);
		free(obj);
		obj = tmp;
	}
}

void			free_env(t_env *e, char *err)
{
	int			i;

	i = 0;
	if (e->obj)
		free_obj(e->obj);
	if (e->light)
		free(e->light);
	if (e->conf)
	{
		while (e->conf[i])
		{
			free(e->conf[i]);
			i++;
		}
	}
	free(e);
	if (err)
		ft_error(err);
}
