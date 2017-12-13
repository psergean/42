/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:50:40 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:50:41 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "./../minilibx_macos/mlx.h"
# include "./../libft/includes/libft.h"
# include "./../libft/includes/get_next_line.h"
# include "./../includes/keypress.h"
# include "./../includes/colors.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define KEY_PRESS_MASK (1L << 0)
# define KEY_PRESS 2
# define STRUCT_NOTIFY_MASK (1L << 17)
# define DESTROY_NOTIFY 17
# define ERR_MALLOC "Error map: failure on memory allocation.\n"
# define CORRUPT_VALUE "Error map: values are corrupt.\n"

typedef struct      s_vec3d
{
  float             x;
  float             y;
  float             z;
}                   t_vec3d;

typedef struct      s_cam
{
  float             x;
  float             y;
  float             z;
  t_vec3d           vpul;
}                   t_cam;

typedef struct      s_env
{
  void				      *mlx;
  void				      *win;
  void				      *img;
  char				      *file;
  int					      width;
  int					      heigth;
  char				      *pxl;
  int					      bpp;
  int				       	size_line;
  int					      endian;
  unsigned int      color;

  t_cam             *cam;
}                   t_env;

int                 main(int ac, char **av);

t_env		            *init_env(t_env *env);
void		            init_img(t_env *env);
t_cam		            *init_cam(t_cam *cam);
t_vec3d		          *init_vpul(t_vec3d *vpul);


int			            ft_exit(t_env *env);
void		            ft_error(t_env *env, char *str);
int			            check_input(int ac);

void                raytracer(t_env *env);

void			          free_malloc(t_env *env);

void				        put_pixel_to_image(t_env *env, int x, int y);

void		            mlx_event_management(t_env *env);
int		           		key_hook(int keycode, t_env *env);
int			            loop_hook(t_env *env);

#endif
