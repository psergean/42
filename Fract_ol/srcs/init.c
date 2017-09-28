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
	return (env);
}

void		init_img(t_env *env)
{
	env->width = (env->fract->x2 - env->fract->x1) * 300;
	env->heigth = (env->fract->y2 - env->fract->y1) * 300;
	env->win = mlx_new_window(env->mlx, env->width, env->heigth, "Fract_ol");
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	env->pxl = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line), &(env->endian));
}

t_fract		*init_mandelbrot_fract()
{
	t_fract		*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	return (fract);
}

t_fract		*init_julia_fract()
{
	t_fract		*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->c_r = 0;
	fract->c_i = 0;
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->x1 = -1;
	fract->x2 = 1;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	return (fract);
}

t_env		*init(char **av, t_env *env)
{
	env = init_env(env);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		env->fract = init_mandelbrot_fract();
		init_img(env);
		env->f = &mandelbrot;
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		env->fract = init_julia_fract();
		init_img(env);
		env->f = &julia;
	}
	else
		ft_error(env, "Error: I can only reading the fractale of Mandelbrot, Julia or ...\n");
	env->f(env);
	return (env);
}
