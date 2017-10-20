/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:45:22 by psergean          #+#    #+#             */
/*   Updated: 2017/10/05 02:00:51 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

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
# define MOTION_MASK_PTR (1L << 6)
# define MOTION_NOTIFY 6

typedef struct    s_cmd
{
  long double     posX;
  long double     posY;
  long double     dirX;
  long double     dirY;
  long double     oldDirX;
  long double     planeX;
  long double     planeY;
  long double     oldPlaneX;
  long double     movespeed;
  long double     rotspeed;
}                 t_cmd;

typedef struct    s_calc
{
  long double     posX;
  long double     posY;
  long double     dirX;
  long double     dirY;
  long double     planeX;
  long double     planeY;
  long double     cameraX;
  long double     rayposX;
  long double     rayposY;
  long double     raydirX;
  long double     raydirY;
  int             mapX;
  int             mapY;
  long double     sideDistX;
  long double     sideDistY;
  long double     deltaDistX;
  long double     deltaDistY;
  long double     perpWallDist;
  int             stepX;
  int             stepY;
  int             hit;
  int             side;
}                 t_calc;

typedef struct		s_env
{
	void			      *mlx;
	void			      *win;
	void			      *img;
	int				      width;
	int				      heigth;
	char			      *pxl;
	int				      bpp;
	int			       	size_line;
	int				      endian;
  int             color;
  int             fd;
  int             **map;
  t_cmd           *cmd;
}					        t_env;

int					main(int ac, char **av);

t_env				*init_env(t_env *env);
void				init_img(t_env *env);
t_env				*init(char **av, t_env *env);
void 		     init_command(t_env *env);

void        read_map(t_env *env);

void        raycasting(t_env *env);
void        calc_pos_and_dir(t_calc *calc, t_env *env, int x);
void        calc_step_and_init_dist(t_calc *calc);
void        calc_if_hit_wall(t_calc *calc, t_env *env);
void        calc_draw_start_end(t_calc *calc, t_env *env, int x);
void        draw(t_calc *calc, t_env *env, int x, int drawstart, int drawend);
int			    loop_hook(t_env *env);

void				put_pixel_to_image(t_env *env, int x, int y);
int				  colors(t_env *env, t_calc *calc);

void				display(t_env *env);

int					key_hook(int keycode, t_env *env);
int					key_hook2(int keycode, t_env *env);
int					key_hook3(int keycode, t_env *env);
int				  key_hook4(int keycode, t_env *env);

int					mouse_hook(int button, int x, int y, t_env *env);
int					mouse_motion_notify(int x, int y, t_env *env);

void 		    mlx_event_management(t_env *env);
void        free_malloc(t_env *env);
void			  free_tab_char(char **tab);
void			  free_tab_int(int **tab);
int					ft_exit(t_env *env);
void				ft_error(t_env *env, char *str);
int					check_input(int ac);

#endif
