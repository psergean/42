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

int   read_file(t_env *env)
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
  return (1);
}


t_env *init_env(t_env *env, char **av)
{
  if (!(env = (t_env*)malloc(sizeof(*env))))
    return (NULL);
  env->fd = open(av[1], O_RDONLY);
  env->mlx = mlx_init();
  env->win = mlx_new_window(env->mlx, 1280, 960, "FdF");
  env->file = ft_strnew(0);
  read_file(env);
  return (env);
}

t_coord *init_coord(t_coord *coord)
{
  if (!(coord = (t_coord*)malloc(sizeof(*coord))))
    return (NULL);
  coord->x_c = 0;
  coord->y_c = 0;
  coord->z_c = 0;
  return (coord);
}
