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
# define PTR_MOTION_MASK (1L << 6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L << 0)
# define KEY_PRESS 2
# define STRUCT_NOTIFY_MASK (1L << 17)
# define DESTROY_NOTIFY 17

typedef struct    s_cmd
{
  double     posX;
  double     posY;
  double     dirX;
  double     dirY;
  double     oldDirX;
  double     planeX;
  double     planeY;
  double     oldPlaneX;
  double     movespeed;
  double     rotspeed;
}                 t_cmd;

typedef struct    s_calc
{
  double     posX;
  double     posY;
  double     dirX;
  double     dirY;
  double     planeX;
  double     planeY;
  double     cameraX;
  double     rayposX;
  double     rayposY;
  double     raydirX;
  double     raydirY;
  int             mapX;
  int             mapY;
  double     sideDistX;
  double     sideDistY;
  double     deltaDistX;
  double     deltaDistY;
  double     perpWallDist;
  int             stepX;
  int             stepY;
  int             hit;
  int             side;
  long double     wallx;
  int             textX;
  int             textY;
}                 t_calc;

typedef struct    s_floor
{
  double          weigth;
  double          floorwallX;
  double          floorwallY;
  double          distwall;
  double          currentdist;
  double          currentfloorX;
  double          currentfloorY;
  int             textX;
  int             textY;
}                 t_floor;

typedef struct    s_id
{
  char            *pxl;
  int             w;
  int             h;
  int             bpp;
  int             endian;
  int             size_line;
}                 t_id;

typedef struct		s_env
{
	void			      *mlx;
	void			      *win;
	void			      *img;
  char            *file;
	int				      width;
	int				      heigth;
	char			      *pxl;
	int				      bpp;
	int			       	size_line;
	int				      endian;
  unsigned int    color;
  int             fd;
  int             **map;
  t_cmd           *cmd;
  t_id            *texture[10];
  int             y;
  int             x;
  int             id;
  int             nb_x;
  int             nb_y;
}					        t_env;

int					  main(int ac, char **av);

t_env				  *init_env(t_env *env);
void				  init_img(t_env *env);
t_env				  *init(char **av, t_env *env);
void		      init_command(t_env *env);

int			      read_file(t_env *env);
void          read_map(t_env *env);
void          init_max(t_env *env);

void          raycasting(t_env *env);
t_calc        *calc_pos_and_dir(t_calc *calc, t_env *env);
t_calc        *calc_step_and_init_dist(t_calc *calc);
t_calc        *calc_if_hit_wall(t_calc *calc, t_env *env);
void          calc_draw_start_end(t_calc *calc, t_env *env);
void          draw(t_calc *calc, t_env *env, int drawstart);
int			      loop_hook(t_env *env);

int				    put_pixel_to_image(t_env *env, int x, int y);
void          texture(t_env *env);
void           calc_texture(t_calc *calc, t_env *env);
void         draw_texture(t_env *env, int x, int y, int color);
int          texture_colors(t_env *env, int x, int y);
void         calc_floor(t_calc *calc, t_env *env);
void         calc_floor_dir(t_calc *calc, t_floor *Floor);

void				  display(t_env *env);

int					  key_hook(int keycode, t_env *env);
int					  key_hook2(int keycode, t_env *env);
int					  key_hook3(int keycode, t_env *env);
int			      key_hook4(int keycode, t_env *env);
int			  	  key_hook5(int keycode, t_env *env);

int					  mouse_hook(int button, int x, int y, t_env *env);
int					  mouse_motion_notify(int x, int y, t_env *env);

void 		      mlx_event_management(t_env *env);
void          free_malloc(t_env *env);
void			    free_tab_char(char **tab);
void			    free_tab_int(int **tab);
int					  ft_exit(t_env *env);
void				  ft_error(t_env *env, char *str);
int					  check_input(int ac);

#endif
