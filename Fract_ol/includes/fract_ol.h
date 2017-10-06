/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:45:22 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 02:00:51 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/includes/libft.h"
# include "./../libft/includes/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define MOTION_MASK_PTR (1L << 6)
# define MOTION_NOTIFY 6

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
	float				zoom_x;
	float				zoom_y;
	int					x;
	int					y;
	int					ite_max;
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
	float			zoom;
	int				ite;
	float			dec_y;
	float			dec_x;
	int				mouse_x;
	int				mouse_y;
	float			x;
	float			y;
	int				fractale;
}					t_env;

int					main(int ac, char **av);
t_env				*init_env(t_env *env);
void 				init_event(t_env *env);
void				init_img(t_env *env);
t_env				*init(char **av, t_env *env);
t_fract				*init_mandelbrot_fract(t_env *env);
void				mandelbrot(t_env *env);
void				mandetlbrot_ite(t_env *env, int x, int y);
t_fract				*init_julia_fract(t_env *env);
void				julia(t_env *env);
void				julia_ite(t_env *env, int x, int y);
t_fract				*init_burningship_fract(t_env *env);
void				burningship(t_env *env);
void				burningship_ite(t_env *env, int x, int y);
t_fract				*init_dendrite_fract(t_env *env);
void				dendrite_ite(t_env *env, int x, int y);
void				dendrite(t_env *env);
t_fract				*init_lapin_fract(t_env *env);
void				lapin_ite(t_env *env, int x, int y);
void				lapin(t_env *env);
t_fract				*init_julia_bis_fract(t_env *env);
void				julia_bis(t_env *env);
void				julia_bis_ite(t_env *env, int x, int y);
void				put_pixel_to_image(t_env *env, int x, int y);
void				colors(t_env *env);
void				display(t_env *env);
int					key_hook(int keycode, t_env *env);
int					key_hook2(int keycode, t_env *env);
int					key_hook3(int keycode, t_env *env);
int					key_hook4(int keycode, t_env *env);
int					key_hook5(int keycode, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);
int					mouse_motion_notify(int x, int y, t_env *env);
void				mouse_moving(t_env *env, int x, int y);
int					ft_exit(t_env *env);
void				ft_error(t_env *env, char *str);
int					check_input(int ac);

#endif
