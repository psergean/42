/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:04:01 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_env		*init_env(t_env *env)
{
	env = (t_env*)malloc(sizeof(*env));
	env->mlx = mlx_init();
	env->zoom = 1;
	return (env);
}

void		init_img(t_env *env)
{
	env->width = 600;
	env->heigth = 600;
	env->win = mlx_new_window(env->mlx, env->width, env->heigth, "Fract_ol");
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
}

t_env		*init(char **av, t_env *env)
{
	env = init_env(env);
	init_img(env);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		env->f = &mandelbrot;
	else if (ft_strcmp(av[1], "julia") == 0)
		env->f = &julia;
	else
		ft_error(env, "Error: I can only reading the fractale of Mandelbrot, Julia or ...\n");
	env->f(env);
	return (env);
}
