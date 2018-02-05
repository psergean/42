/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <tzaaboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:08:04 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/02/01 18:53:16 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define ESC 53

/*typedef struct		s_dir
{
	double			x;
	double			y;
	double			z;
}					t_dir;*/

typedef struct		s_dir
{
	double			x;
	double			y;
	double			z;
}					t_dir;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_obj
{
	int				id;
	char			*type;
	t_dir			pos;
	t_dir			dir;
	double			rad;
	double			h;
	t_color			color;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_cam
{
	t_dir			pos;
	t_dir			dir;
	t_dir			vpsz;
	t_dir			vpul;
	double			xi;
	double			yi;
}					t_cam;

typedef struct		s_light
{
	t_dir			pos;
}					t_light;

typedef struct		s_ray
{
	t_dir			vdir;
	t_dir			ldir;
	double			dist;
	double			ref;
//	int				obj_id;
	t_obj			*obj;
	t_dir			inter;
}					t_ray;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				sline;
	int				endian;
	char			**conf;
	t_cam			*cam;
	t_ray			ray;
	t_light			*light;
	t_obj			*obj;
}					t_env;

double				vector_dot(t_dir vec1, t_dir vec2);
t_dir				vector_sub(t_dir vec1, t_dir vec2);
t_dir				vector_product(t_dir vec, double n);
double				hit_cylinder(t_dir start, t_obj *objct, t_dir dir);
int					lhit_cylinder(t_dir start, t_obj *objct, t_dir dir, t_env *e);
double				hit_plan(t_dir start, t_obj *objct, t_dir dir);
int					lhit_plan(t_dir start, t_obj *objct, t_dir dir,
					t_env *e);
void				init_val(t_env *e, char *file);
void				init_sphere(t_obj *sp, char **conf, unsigned int s, int *i);
void				init_plane(t_obj *pl, char **conf, unsigned int s, int *i);
void				init_cyl_cone(t_obj *obj, char **conf, char *type, int *i);
void				free_env(t_env *e, char *err);
void				check_conf(t_env *e, char **conf, int i);
void				check_value(t_env *e, char **conf, int j);
void				check_tag(t_env *e, char **conf, int j);
void				check_sphere(t_env *e, char **conf, int j, int pos);
void				check_plane(t_env *e, char **conf, int j, int pos);
void				check_cyl_cone(t_env *e, int j, int pos, int dir);
void				get_conf(t_env *e, char *file);
double				get_val(char *line, unsigned int s);
size_t				val_len(char *line, unsigned int s);
void				get_color(t_obj *obj, char *line);
double				ft_atod(const char *nptr, int dot, int i);
int					rt(t_env *e);
void					get_dir(t_env *e, int x, int y);
int					hit(t_env *e);
double				hit_sphere(t_dir start, t_obj *objct, t_dir dir);
void				get_vp(t_cam *cam);
int					get_ldir(t_env *e);
int					lhit(t_env *e);
int					lhit_sphere(t_dir start, t_obj *objct, t_dir dir,
					t_env *e);
#endif
