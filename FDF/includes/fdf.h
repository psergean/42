#ifndef FDF_H
# define FDF_H

# include "./../minilibx_macos/mlx.h"
# include "./../Libft/includes/libft.h"
# include "./../Libft/includes/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 32


typedef struct  s_env
{
  char    **tab;
  int     fd;
  void    *mlx;
  void    *win;
  char    *file;
//  int   x;
//  int   y;
//  int   weigth;
//  int   heigth;
}               t_env;

typedef struct  s_coord
{
  int     x_c;
  int     y_c;
  int     z_c;
}               t_coord;

int           main(int ac, char **av);
int           check_input(int ac);
t_env         *init_env(t_env *env, char **av);
int           read_file(t_env *env);
int           parse(t_env *env);
t_coord       *init_coord(t_coord *coord);
int           key_funct(t_env *env);
int           my_key_funct(int keycode);
int           key_hook(int keycode, t_env *env);

#endif
