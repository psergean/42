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


typedef struct		s_fract
{
}					t_fract;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_fract			*mandelbrot;
	t_fract			*julia;
}					t_env;

int					main(int ac, char **av);
t_env				*init(char **av, t_env *env);



int					key_hook(int keycode, t_env *env);

#endif
