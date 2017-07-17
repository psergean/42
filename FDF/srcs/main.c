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

int   check_input(int ac)
{
  if (ac != 2)
  {
    ft_putstr_fd("usage:./fdf file_map.\n", 2);
    return (0);
  }
  return (1);
}

int   main(int ac, char **av)
{
  t_env *env = NULL;

  if (!env)
  {
    env = init_env(env, &av[1]);
  }
  if (!(check_input(ac)))
    return (0);
  parse(env);
  key_funct(env);
  mlx_key_hook(env->win, key_hook, env);
  mlx_loop(env->mlx);
  return (0);
}
