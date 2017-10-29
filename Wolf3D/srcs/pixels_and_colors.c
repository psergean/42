/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_and_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 01:57:34 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

int				put_pixel_to_image(t_env *env, int x, int y)
{
	int				i;

	i = (x * (env->bpp / 8)) + (y * env->size_line);
	if (!(ft_memcpy(env->pxl + i, &env->color, 4)))
		return (-1);
	return (1);
}

// unsigned int				colors(t_env *env, t_calc *calc)
// {
// 	if (calc->side == 1)
// 	{
// 		if (calc->stepY == -1)
// 		{
// 			return (env->color = (unsigned int)LIGTHSALMON);
// 		}
// 		if (calc->stepY == 1)
// 		{
// 			return (env->color = (unsigned int)SALMON);
// 		}
// 	}
// 	if (calc->stepX == -1)
// 		return (env->color = (unsigned int)TAN);
// 	else
// 		return (env->color = (unsigned int)DARKSALMON);
// }

void          draw(t_calc *calc, t_env *env, int drawstart)
{
	env->y = -1;
	while(++env->y < drawstart)
	{
		// env->color = (unsigned int)DARKSLATE;
		// put_pixel_to_image(env, env->x, env->y);
		// env->y++;
	}
	env->y--;
	calc_texture(calc, env);
	// while(++env->y <= drawend && env->y < env->heigth)
	// {
	// 	colors(env, calc);
	// 	put_pixel_to_image(env, env->x, env->y);
	// }
	calc_floor(calc, env);
	// while(++env->y < env->heigth)
	// {
	// 	env->color = (unsigned int)BEIGE;
	// 	put_pixel_to_image(env, env->x, env->y);
	// }
}
