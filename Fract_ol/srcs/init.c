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
	env->ite = 0;
	env->dec_y = 0.0;
	env->dec_x = 0.0;
	return (env);
}

void		init_img(t_env *env)
{
	env->width = 1000;
	env->heigth = 1000;
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
	else if (ft_strcmp(av[1], "burningship") == 0)
		env->f = &burningship;
	else if (ft_strcmp(av[1], "dendrite") == 0)
		env->f = &dendrite;
	else if (ft_strcmp(av[1], "lapin_de_douady") == 0)
		env->f = &lapin;
	else if (ft_strcmp(av[1], "julia_bis") == 0)
		env->f = &julia_bis;
	else if (ft_strcmp(av[1], "tapis_de_sierpinski") == 0)
		env->f = &tapis;
	else if (ft_strcmp(av[1], "test") == 0)
		env->f = &test;
	else
		ft_error(env, "Error: I can only reading the fractale of Mandelbrot, Julia,\n Dendrite, Burningship, Lapin_de_douady or Tapis_de_sierpinski.\n");
	env->f(env);
	return (env);
}
