/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2016/11/18 17:25:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int       read_file(t_env *env)
{
  char  buff[BUFF_SIZE + 1];
  char  *tmp;
  int   ret;

  while ((ret = read(env->fd, buff, BUFF_SIZE)) > 0)
  {
    buff[ret] = '\0';
    tmp = ft_strjoin(env->file, buff);
    env->file = ft_strdup(tmp);
  }
  if (ret == -1)
    return (0);
  close(env->fd);
  return (1);
}

t_env     *init_env(t_env *env, char **av)
{
  if (!(env = (t_env*)malloc(sizeof(*env))))
    return (NULL);
  env->fd = open(av[1], O_RDONLY);
  env->mlx = mlx_init();
  env->win = mlx_new_window(env->mlx, 900, 600, "FdF");
  env->file = ft_strnew(0);
  if ((env->fd = open(av[1], O_RDONLY)) < 0 || !(read_file(env)))
  {
    perror(av[1]);
    ft_exit(env);
  }
  env->nb_x = 0;
  env->nb_y = 0;
  init_max(env);
  env->nb = env->nb_x * env->nb_y;
  return (env);
}

t_calc    *init_calc(t_env *env, t_calc *calc, int j)
{
  calc->xi = env->coord_f[j].xi;
  calc->yi = env->coord_f[j].yi;
  calc->xf = env->coord_f[j].xf;
  calc->yf = env->coord_f[j].yf;
  calc->dx = calc->xf - calc->xi;
  calc->dy = calc->yf - calc->yi;
  calc->xinc = (calc->dx > 0) ? 1 : -1;
  calc->yinc = (calc->dy > 0) ? 1 : -1;
  printf("dx = %f ", calc->dx);
  printf("dy = %f\n", calc->dy);
//  printf("%d ", calc->yi);
//  printf("%d\n\n", calc->yf);
//  printf("env->coord[%d] xi = %d ", j, env->coord_f[j].xi);
//  printf("env->coord[%d] yi = %d\n", j, env->coord_f[j].yi);
//  printf("env->coord[%d] xf = %d ", j, env->coord_f[j].xf);
//  printf("env->coord[%d] yf = %d\n\n", j, env->coord_f[j].yf);
  return (calc);
}

void  init_coord(t_env *env, char *z, int x, int y, int k)
{
  env->coord[k].xi = x;
  env->coord[k].yi = y;
  env->coord[k].xf = x + 1;
  env->coord[k].yf = y + 1;
  if (x + 1 > env->nb_x)
    env->coord[k].xf = x;
  env->coord[k].yf = y + 1;
  if (y + 1 > env->nb_y)
    env->coord[k].yf = y;
  env->coord[k].z = ft_atoi(z);
  env->coord[k].z += 1;
}

void    init_max(t_env *env)
{
  int   x;
  int   y;

  env->y_split = ft_strsplit(env->file, '\n');
  env->x_split = ft_strsplit(env->y_split[1], ' ');
  x = 0;
  while(env->x_split[x] != '\0')
    x++;
  env->nb_x = x;
  y = 0;
  while(env->y_split[y] != '\0')
    y++;
  env->nb_y = y;
}
