/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

void 		init_event(t_env *env)
{
	env->zoom = 1;
	env->ite = 0;
	env->dec_y = 0.0;
	env->dec_x = 0.0;
	env->x = 0;
	env->y = 0;
	env->r_inc = 5;
	env->g_inc = 10;
	env->b_inc = 2;
}

t_env		*init_env(t_env *env)
{
	env = (t_env*)malloc(sizeof(*env));
	env->mlx = mlx_init();
	init_event(env);
	return (env);
}

void		init_img(t_env *env)
{
	env->width = 1000;
	env->heigth = 1000;
	env->win = mlx_new_window(env->mlx, env->width, env->heigth, "Fract_ol");
	env->img = mlx_new_image(env->mlx, env->width, env->heigth);
	env->pxl = mlx_get_data_addr(env->img, &(env->bpp),
			&(env->size_line), &(env->endian));
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
	else
	{
		ft_putstr_fd("Error:  I can only reading the fractale\n", 2);
		ft_putstr_fd("\tof Mandelbrot, Julia, Dendrite,\n", 2);
		ft_error(env, "\tBurningship or Lapin_de_douady.\n");
	}
	env->f(env);
	return (env);
}
