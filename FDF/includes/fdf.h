#ifndef FDF_H
# define FDF_H

# include "./../minilibx_macos/mlx.h"
# include "./../Libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 32


typedef struct  s_env
{
  int fd;
  void *mlx;
  void *win;
//  int   x;
//  int   z;
//  int   weigth;
//  int   heigth;
}               t_env;

int   main(int ac, char **av);
int   check_input(int ac);
static t_env *init_data(t_env *env, char **av);
int   key_funct(t_env *env);
int   my_key_funct(int keycode);

#endif
