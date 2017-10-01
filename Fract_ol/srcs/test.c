/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:04:17 by psergean          #+#    #+#             */
/*   Updated: 2017/09/16 15:30:50 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fract_ol.h"

t_fract		*init_test_fract()
{
	t_fract		*fract;

	fract = NULL;
	fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	fract->i = 0;
  fract->x = 0;
  fract->y = 0;
	return (fract);
}

void				test_ite(t_env *env, int x, int y)
{
	env->fract->i = 0;
  env->fract->x = x;
  env->fract->y = y;
	while (env->fract->i < ITE_MAX && (env->fract->x > 0 || env->fract->y > 0))
	{
    if (env->fract->x == (log(8) / log(3)) || env->fract->y == (log(8) / log(3)))
      break;
    env->fract->i++;
	}
	if (env->fract->i != ITE_MAX)
	{
    printf("i = %d\n", env->fract->i);
		env->color = env->fract->i * 255 / 10;
		put_pixel_to_image(env, x, y);
	}
}

void			test(t_env *env)
{
	int			x;
	int			y;

	x = 0;
	env->fract = init_test_fract();
	while (x < env->width)
	{
		y = 0;
		while (y < env->heigth)
		{
			test_ite(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
