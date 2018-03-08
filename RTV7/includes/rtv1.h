/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:18:50 by tapperce          #+#    #+#             */
/*   Updated: 2018/03/07 15:11:35 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include "../libvec/includes/libvec.h"
# include "../minilibx_macos/mlx.h"



# include <stdio.h>

# define WIDTH 1080
# define HEIGHT 1080
# define ESC 53
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE 3
# define KEY_RELEASE_MASK (1L<<1)

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_obj
{
	char			*type;
	double			k;
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			scale;
	t_color			color;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_ray
{
	t_vec3			pos;
	t_vec3			dir;
	double			tnear;
	t_vec3			inter;
	t_obj			*obj;
}					t_ray;

typedef struct		s_cam
{
	t_vec3			pos;
	t_vec3			dir;
	double			**m;
}					t_cam;

typedef struct		s_light
{
	t_vec3			pos;
	t_color			color;
	double			i;
	struct s_light	*next;
}					t_light;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	char			**conf;
	int				bpp;
	int				sline;
	int				endian;
	t_ray			prim;
	t_ray			rayl;
	t_cam			cam;
	t_obj			*obj;
	t_light			*light;
}					t_env;

int					close_win(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					ft_loop_hook(t_env *e);

void				init_val(t_env *e, char *file);
void				init_objs(t_obj *obj, char **conf, char *type, int *i);
void				new_obj(t_env *e);

void				check_conf(t_env *e, char **conf, int i);
void				check_value(t_env *e, char **conf, int j);
void				check_tag(t_env *e, char **conf, int j);
void				check_objs(t_env *e, int j, int scl, int dif);
void				check_short_double(t_env *e);

void				get_conf(t_env *e, char *file);
double				get_val(char *line, unsigned int s);
size_t				val_len(char *line, unsigned int s);
void				get_color(t_color *color, char *line);
double				ft_atod(const char *nptr, int dot, int i);

void				free_env(t_env *e, char *err);
int					build_prim(int x, int y, t_env *e);
int					rt(t_env *e);
double				intersect(t_env *e);
double				light(t_env *e);


// <-------------- lighting in Progress -------------->

static double	ambient_light(double i, double k, double s);
static double	diffuse_light(double i, double k, double s, t_env *e);


// <-------------- lighting in Progress -------------->


#endif
