 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/04 23:53:56 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/wolf3D.h"

void        read_map(t_env *env)
{
  int     x;
  int     y;
  char    *line;
  char    **map;

  y = 0;
  if (!(env->map = (int**)ft_memalloc(sizeof(int *) * 24)))
    return (ft_error(env, "Error Map: failure on memory allocation\n"));
  while(get_next_line(env->fd, &line) == 1)
  {
    if (!(env->map[y] = (int*)ft_memalloc(sizeof(int) * 24)))
      return (ft_error(env, "Error map: failure on memory allocation.\n"));
    map = ft_strsplit(line, ',');
    x = 0;
    while(map[x] != '\0')
    {
      env->map[y][x] = ft_atoi(map[x]);
      x++;
    }
    y++;
    free_tab_char(map);
    free(line);
  }
}
