/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

void		init_img(t_env *env)
{
	env->width = 512;
	env->heigth = 384;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->heigth, "Wolf3D");
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	env->pxl = mlx_get_data_addr(env->img, &(env->bpp),
			&(env->size_line), &(env->endian));
}

void 		mlx_management(t_env *env)
{
  mlx_key_hook(env->win, key_hook, env);
  mlx_mouse_hook(env->win, mouse_hook, env);
  mlx_hook(env->win, MOTION_NOTIFY, MOTION_MASK_PTR,
      mouse_motion_notify, env);
  mlx_hook(env->win, 17, (1L << 17), ft_exit, env);
  mlx_loop(env->mlx);
}

void			free_coord(t_env *env)
{
  free(env->coord);
}

void			free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void   free_malloc(t_env *env)
{
  free_coord(env);
  free(env);
}
