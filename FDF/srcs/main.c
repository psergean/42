/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2016/11/18 17:25:42 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static t_env *init_data(t_env *env, char **av)
{
  if (!(env = (t_env*)malloc(sizeof(*env))))
    return (NULL);
  env->fd = open(av[1], O_RDONLY);
  env->mlx = mlx_init();
  env->win = mlx_new_window(env->mlx, 1280, 960, "FdF");
  return (env);
}

int   check_input(int ac)
{
  if (ac != 2)
  {
    ft_putstr_fd("usage:./fdf file_map.\n", 2);
    return (0);
  }
  return (1);
}

int   my_key_funct(int keycode)
{
  printf("key event %d\n", keycode);
  return (0);
}

int   key_funct(t_env *env)
{
  return (mlx_key_hook(env->win, my_key_funct, 0));
}


int   main(int ac, char **av)
{
  static t_env *env = NULL;

  if (!env)
  {
    env = init_data(env, &av[1]);
  }
  if (!(check_input(ac)))
    return (0);
  key_funct(env);
  //key_hook(env);
  mlx_loop(env->mlx);
}
