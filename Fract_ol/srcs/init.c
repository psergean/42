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
	env = (t_env*)ft_memalloc(sizeof(t_env);
	return (env);
}

void		init_fract(char **av, t_env *env)
{
	fract = (t_fract*)ft_memalloc(sizeof(t_fract);
	if (ft_strcmp(av, "mandelbrot") == 0)
		env->f = &mandelbrot;
	else if (ft_strcmp(av, "julia") == 0)
		env->f = &julia;
	env->f(env);
}

void		init(char **av, t_env *env)
{
	if (!env = init_env(env))
		ft_error(env, "Error: I can't malloc env.\n");
	if (!(init_fract(av, env)))
		ft_error(env, "Error: I can only reading the fractale of Mandelbrot, Julia or ...\n");
}
