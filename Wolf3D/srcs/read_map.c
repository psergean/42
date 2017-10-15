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
  int     i;
  int     x;
  int     y;
  char    *map;
  char    **map_split;

  i = 0;
  y = 1;
  env->coord = (t_coord*)ft_memalloc(sizeof(t_coord) * 576 + 1);
  while(get_next_line(env->fd, &map) == 1)
  {
    map_split = ft_strsplit(map, ',');
    x = 0;
    while(map_split[x] != '\0')
    {
      // printf("%c", map_split[x][0]);
      init_coord(env, x, y , map_split[x], i);
      // printf("%d ", env->coord[i].z);
      i++;
      x++;
    }
    // printf("\n");
    y++;
    free_tab(map_split);
    // printf("%s\n", map);
    free(map);
  }
  // printf("i = %d\n", i);
}
