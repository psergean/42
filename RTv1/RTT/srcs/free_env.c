/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:51:03 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/01/22 18:36:15 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	if (e->cam)
		free(e->cam);
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
	ft_error(err);
}
