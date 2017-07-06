#ifndef FDF_H
# define FDF_H

# include "./../minilibx_macos/mlx.h"
# include "./../Libft/includes/libft.h"


typedef struct  s_env
{
  void *mlx;
  void *win;
  int   x;
  int   y;
  int   weigth;
  int   heigth;
}               t_env;

int   main();

#endif
