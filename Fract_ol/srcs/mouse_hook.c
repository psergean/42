/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:49:35 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 00:49:40 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

int				mouse_hook(int button, int x, int y, t_env *env)
{
	printf("button == %d, (%d:%d), %f\n", button, x, y, env->zoom);
	if (button == 4 || button == 5)
	{
		env->zoom = button == 4 ? env->zoom - 0.2 : env->zoom + 0.2;
		env->x = button == 4 ? env->x + (float)(env->width / 2 - x) :
			env->x - (float)(env->width / 2 - x);
		env->y = button == 4 ? env->y + (float)(env->heigth / 2 - y) :
			env->y - (float)(env->heigth / 2 - y);
		if (env->zoom < 1)
			env->zoom = 1;
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->width, env->heigth);
		env->pxl = mlx_get_data_addr(env->img, &(env->bpp),
				&(env->size_line), &(env->endian));
	}
	return (0);
}

int				mouse_motion_notify(int x, int y, t_env *env)
{
	if (x < 0 || x >= env->width || y < 0 || y >= env->heigth)
		return (0);
	env->mouse_x = x;
	env->mouse_y = y;
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	env->pxl = mlx_get_data_addr(env->img, &(env->bpp),
			&(env->size_line), &(env->endian));
	env->f(env);
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FFFFFF, "Help : h");
	return (1);
}
