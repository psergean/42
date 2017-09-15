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
# define WIDTH 1260
# define HEIGTH 980
# define SIZE_WIN WIDTH * HEIGTH


typedef struct		s_fract
{
}					t_fract;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
//	char			*pxl;
	int				width;
	int				heigth;
	t_fract			*fract;
	void			(*f)(struct s_env *);
}					t_env;

int					main(int ac, char **av);

t_env				*init_env(t_env *env);
t_fract				*init_fract();
t_env				*init(char **av, t_env *env);

void				mandelbrot(t_env *env);
void				julia(t_env *env);

void				display(t_env *env);
int					key_hook(int keycode, t_env *env);

void				ft_exit(t_env *env);
void				ft_error(t_env *env, char *str);
int					check_input(int ac);

#endif
