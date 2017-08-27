/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:49:11 by psergean          #+#    #+#             */
/*   Updated: 2017/08/26 15:49:34 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/includes/libft.h"
# include "./../libft/includes/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define BUFF_SIZE 32
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef	struct		s_coord
{
	int				xi;
	int				yi;
	int				z;
}					t_coord;

typedef	struct		s_coord_f
{
	float			xi;
	float			yi;
    float           z;
}					t_coord_f;

typedef struct		s_env
{
	int				fd;
	void			*mlx;
	void			*win;
	char			*file;
	t_coord			*coord;
	t_coord_f		*coord_f;
	int				nb_x;
	int				nb_y;
	int				nb;
	char			**x_split;
	char			**y_split;
	float			zinc;
	int				zoom;
	int				dec_x;
	int				dec_y;
	// int				view;
}					t_env;

typedef struct		s_calc
{
	float			xi;
	float			yi;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	float			cumul;
	float			z;
}					t_calc;

int					main(int ac, char **av);
int					check_input(int ac);
t_coord				*parse(t_env *env);
void				ft_exit(t_env *env);
t_env				*init_env(t_env *env, char **av);
void				init_max(t_env *env);
void				init_coord(t_env *env, int x, int y, int k);
void				init_calc(t_env *env, t_calc *calc, int i, int j);
int					read_file(t_env *env);
t_coord_f			*view(t_env *env);
void				init_coord_iso(t_env *env, int i);
// void				init_coord_para(t_env *env, int i);
int					my_key_funct(int keycode);
int					key_hook(int keycode, t_env *env);
void				draw_line(t_env *env, int i, int j);
void				draw_line_x(t_env *env, t_calc *calc);
void				draw_line_y(t_env *env, t_calc *calc);
void				draw(t_env *env);
void				display(t_env *env);
int					check_file(t_env *env);

#endif
