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
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGTH, "Fract_ol");
	env->width = WIDTH;
	env->heigth = HEIGTH;
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	return (env);
}

t_fract		*init_fract()
{
	t_fract		*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	return (fract);
}

t_env		*init(char **av, t_env *env)
{
	env = init_env(env);
	env->fract = init_fract();
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		env->f = &mandelbrot;
	else if (ft_strcmp(av[1], "julia") == 0)
		env->f = &julia;
	else
		ft_error(env, "Error: I can only reading the fractale of Mandelbrot, Julia or ...\n");
	env->f(env);
	return (env);
}
