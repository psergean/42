/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:46:16 by psergean          #+#    #+#             */
/*   Updated: 2017/09/11 16:44:10 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int		my_key_funct(int keycode)
{
	printf("key event %d\n", keycode);
	return (0);
}

int		key_hook_2(int keycode, t_env *env)
{
	if (keycode == 124 || keycode == 123)
		env->dec_x += keycode == 124 ? 10 : -10;
	if (keycode == 6 || keycode == 7)
		env->zoom += keycode == 6 ? 1 : -1;
	if (keycode == 15)
	{
		env->zinc = 5;
		env->dec_x = 600;
		env->dec_y = 300;
		env->zoom = 35;
	}
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		free_tab(env->y_split);
		free(env);
		exit(0);
	}
	if (keycode == 24)
		env->zinc += 1;
	if (keycode == 27 && env->zinc > 0)
		env->zinc -= 1;
	if (keycode == 126 || keycode == 125)
		env->dec_y += keycode == 126 ? -10 : 10;
	key_hook_2(keycode, env);
	mlx_clear_window(env->mlx, env->win);
	env->coord = parse(env);
	env->coord_f = view(env);
	draw(env);
	display(env);
	return (0);
}
