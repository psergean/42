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

int			loop_hook(t_env *env)
{
	raycasting(env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void 		mlx_event_management(t_env *env)
{
  mlx_key_hook(env->win, key_hook, env);
	mlx_hook(env->win, KEY_PRESS, KEY_PRESS_MASK, key_hook, env);
	mlx_hook(env->win, MOTION_NOTIFY, PTR_MOTION_MASK,
		mouse_motion_notify, env);
	mlx_hook(env->win, DESTROY_NOTIFY, STRUCT_NOTIFY_MASK, ft_exit, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
  mlx_loop(env->mlx);
}
