/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 16:07:44 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3d.h"

void			texture(t_env *env)
{
	int			h;
	int			w;

	env->texture[0] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu337.XPM", &w, &h);
	env->texture[0]->pxl = mlx_get_data_addr(env->texture[0],
			&(env->texture[0]->bpp), &(env->texture[0]->size_line),
				&(env->texture[0]->endian));
	env->texture[1] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu6522.XPM", &w, &h);
	env->texture[1]->pxl = mlx_get_data_addr(env->texture[1],
			&(env->texture[1]->bpp), &(env->texture[1]->size_line),
				&(env->texture[1]->endian));
	env->texture[2] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu7623.XPM", &w, &h);
	env->texture[2]->pxl = mlx_get_data_addr(env->texture[2],
			&(env->texture[2]->bpp), &(env->texture[2]->size_line),
				&(env->texture[2]->endian));
	env->texture[3] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu339.XPM", &w, &h);
	env->texture[3]->pxl = mlx_get_data_addr(env->texture[3],
			&(env->texture[3]->bpp), &(env->texture[3]->size_line),
				&(env->texture[3]->endian));
	texture2(env, h, w);
}

void			texture2(t_env *env, int h, int w)
{
	env->texture[4] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu4.xpm", &w, &h);
	env->texture[4]->pxl = mlx_get_data_addr(env->texture[4],
			&(env->texture[4]->bpp), &(env->texture[4]->size_line),
				&(env->texture[4]->endian));
	env->texture[5] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu1.XPM", &w, &h);
	env->texture[5]->pxl = mlx_get_data_addr(env->texture[5],
			&(env->texture[5]->bpp), &(env->texture[5]->size_line),
				&(env->texture[5]->endian));
	env->texture[6] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridu2.XPM", &w, &h);
	env->texture[6]->pxl = mlx_get_data_addr(env->texture[6],
			&(env->texture[6]->bpp), &(env->texture[6]->size_line),
				&(env->texture[6]->endian));
	env->texture[7] = mlx_xpm_file_to_image(env->mlx,
			"pics/eridufloor1.XPM", &w, &h);
	env->texture[7]->pxl = mlx_get_data_addr(env->texture[7],
			&(env->texture[7]->bpp), &(env->texture[7]->size_line),
				&(env->texture[7]->endian));
	env->texture[8] = mlx_xpm_file_to_image(env->mlx,
			"pics/efloor542.XPM", &w, &h);
	env->texture[8]->pxl = mlx_get_data_addr(env->texture[8],
			&(env->texture[8]->bpp), &(env->texture[8]->size_line),
				&(env->texture[8]->endian));
}

void			init_calc_texture(t_calc *calc)
{
	calc->wallx -= floor((calc->wallx));
	calc->textx = (int)(calc->wallx * (double)64);
	calc->textx = 64 - calc->textx - 1;
}

void			calc_texture(t_calc *calc, t_env *env)
{
	int			d;
	int			lineheigth;
	int			drawstart;
	int			drawend;

	lineheigth = abs((int)(env->heigth / calc->perpwalldist));
	drawstart = -lineheigth / 2 + env->heigth / 2;
	drawend = lineheigth / 2 + env->heigth / 2;
	if (drawstart < 0)
		drawstart = 0;
	if (drawend >= env->heigth)
		drawend = env->heigth - 1;
	if (calc->side == 0)
		calc->wallx = calc->rayposy + calc->perpwalldist * calc->raydiry;
	else
		calc->wallx = calc->rayposx + calc->perpwalldist * calc->raydirx;
	init_calc_texture(calc);
	env->id = env->map[calc->mapy][calc->mapx] - 1;
	while (++env->y < drawend)
	{
		d = env->y * 256 - env->heigth * 128 + lineheigth * 128;
		calc->texty = ((d * 64) / lineheigth) / 256;
		draw_texture(env, env->x, env->y,
				texture_colors(env, calc->textx, calc->texty));
	}
}
