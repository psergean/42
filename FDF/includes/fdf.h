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

typedef struct    s_coord
{
  int     xi;
  int     yi;
  int     z;
}                 t_coord;

typedef struct    s_coord_f
{
  float     xi;
  float     yi;
  float     xf;
  float     yf;
}                 t_coord_f;

typedef struct    s_env
{
  int       fd;
  void      *mlx;
  void      *win;
  char      *file;
  t_coord   *coord;
  t_coord_f *coord_f;
  int       nb_x;
  int       nb_y;
  int       nb;
  char      **x_split;
  char      **y_split;
}                 t_env;

typedef struct    s_calc
{
  float     xi;
  float     yi;
  float     xf;
  float     yf;
  float     dx;
  float     dy;
  int     xinc;
  int     yinc;
  float     cumul;
}                 t_calc;

int           main(int ac, char **av);
int           check_input(int ac);
t_coord       *parse(t_env *env);
void          ft_exit(t_env *env);
t_env         *init_env(t_env *env, char **av);
void          init_max(t_env *env);
void          init_coord(t_env *env, char *z, int x, int y, int k);
void          init_calc(t_env *env, t_calc *calc, int j);
int           read_file(t_env *env);
t_coord_f       *view_para(t_env *env);
void          init_coord_f(t_env *env, int i);
int           key_funct(t_env *env);
int           my_key_funct(int keycode);
int           key_hook(int keycode, t_env *env);
void          draw_line(t_env *env, int j);
void          draw_line_x(t_env *env, t_calc *calc);
void          draw_line_y(t_env *env, t_calc *calc);
void          draw(t_env *env);
void          display(t_env *env);


#endif