#include "./../includes/fdf.h"

void        init_coord_f(t_env *env, int i)
{
  env->coord_f[i].xi = (env->coord[i].xi + 0.7 ) * env->coord[i].z;
  env->coord_f[i].yi = ((env->coord[i].yi + 0.7) / 2) * env->coord[i].z;
  env->coord_f[i].xf = (env->coord[i].xf + 0.7) * env->coord[i + 1].z;
  env->coord_f[i].yf = ((env->coord[i].yf + 0.7) / 2) * env->coord[i + 1].z;
  if (i == env->nb - 1)
  {
    env->coord_f[i].xf = (env->coord[i].xf + 0.7) * (env->coord[i].z);
    env->coord_f[i].yf = ((env->coord[i].yf + 0.7) / 2) * (env->coord[i].z);
  }
//  mlx_pixel_put(env->mlx, env->win, env->coord_f[i].xi, env->coord_f[i].yi, 0x00FFFFFF);
//  printf("env->coord[%d] xi = %f ", i, env->coord_f[i].xi);
//  printf("env->coord[%d] yi = %f\n", i, env->coord_f[i].yi);
//  printf("env->coord[%d] xf = %f ", i, env->coord_f[i].xf);
//  printf("env->coord[%d] yf = %f\n\n", i, env->coord_f[i].yf);
}

t_coord_f     *view_para(t_env *env)
{
  int     i;

  i = 0;
  env->coord_f = (t_coord_f*)ft_memalloc(sizeof(t_coord_f) * env->nb + 1);
  while(i < env->nb)
  {
    init_coord_f(env, i);
    i++;
  }
  return(env->coord_f);
}
