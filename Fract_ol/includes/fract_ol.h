/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:45:22 by psergean          #+#    #+#             */
/*   Updated: 2017/09/14 13:18:14 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/includes/libft.h"
# include "./../libft/includes/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define ITE_MAX 150

typedef struct		s_fract
{
	float				c_r;
	float				c_i;
	float				z_r;
	float				z_i;
	int					i;
	float				x1;
	float				x2;
	float				y1;
	float				y2;
}					t_fract;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				width;
	int				heigth;
	char			*pxl;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	t_fract			*fract;
	void			(*f)(struct s_env *);
}					t_env;

int					main(int ac, char **av);

t_env				*init_env(t_env *env);
void				init_img(t_env *env);
t_fract			*init_mandelbrot_fract();
t_fract			*init_julia_fract();
t_env				*init(char **av, t_env *env);

void				mandelbrot(t_env *env);
void				mandelbrot_ite(t_env *env, int x, int y);
void				julia(t_env *env);
void				julia_ite(t_env *env, int x, int y);

void 				put_pixel_to_image(t_env *env, int x, int y);
void				display(t_env *env);
int					key_hook(int keycode, t_env *env);

void				ft_exit(t_env *env);
void				ft_error(t_env *env, char *str);
int					check_input(int ac);

#endif
