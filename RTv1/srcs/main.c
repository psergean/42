/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:49:25 by psergean          #+#    #+#             */
/*   Updated: 2017/12/13 15:49:29 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

int       main(int ac, char **av)
{
  t_env	*env;

  env = NULL;
  if (check_input(ac) == -1)
    return (-1);
  av[1] = "blabla";
  if (!env)
    env = init_env(env);
  mlx_event_management(env);
  // free_malloc(env);
  return (0);
}
