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

int			read_file(t_env *env)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(env->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(env->file, buff);
		free(env->file);
		env->file = ft_strdup(tmp);
		free(tmp);
	}
	if (ret == -1)
		return (0);
	close(env->fd);
	return (1);
}

void        init_max(t_env *env)
{
  char    **mapline;
	char		**mappoint;
  int     x;
	int			y;

	y = 0;
	mapline = ft_strsplit(env->file, '\n');
  while(mapline[y])
  {
		mappoint = ft_strsplit(mapline[y], ',');
		x = 0;
		while(mappoint[x] != '\0')
			x++;
    y++;
		free_tab_char(mappoint);
  }
	free_tab_char(mapline);
	env->nb_x = x;
	env->nb_y = y;
}

// void        read_map(t_env *env)
// {
//   char    *line;
//   char    **map;
//
//   env->y = -1;
//   if (!(env->map = (int**)ft_memalloc(sizeof(int *) * 24)))
//     return (ft_error(env, "Error Map: failure on memory allocation\n"));
//   while(get_next_line(env->fd, &line) == 1)
//   {
//     map = ft_strsplit(line, ',');
//     if (!(env->map[++env->y] = (int*)ft_memalloc(sizeof(int) * (24))))
//       return (ft_error(env, "Error map: failure on memory allocation.\n"));
//     env->x = -1;
//     while(map[++env->x] != '\0')
//     {
//       env->map[env->y][env->x] = ft_atoi(map[env->x]);
//       if (ft_isdigit(env->map[env->y][env->x]) == -1)
//         return (ft_error(env, "Error map: values are corrupt.\n"));
//     }
//     if (env->x != 24)
//       return (ft_error(env, "Error map: values are corrupt.\n"));
//     free_tab_char(map);
//     free(line);
//   }
//   if (env->y != 24 - 1)
//     return (ft_error(env, "Error map: values are corrupt.\n"));
// }

void        read_map(t_env *env)
{
  char    **mapline;
  char    **mappoint;

  env->y = 0;
  if (!(env->map = (int**)ft_memalloc(sizeof(int *) * env->nb_y)))
    return (ft_error(env, "Error Map: failure on memory allocation\n"));
  mapline = ft_strsplit(env->file, '\n');
  while(mapline[env->y] != '\0')
  {
    mappoint = ft_strsplit(mapline[env->y], ',');
    if (!(env->map[env->y] = (int*)ft_memalloc(sizeof(int) * (env->nb_x))))
      return (ft_error(env, "Error map: failure on memory allocation.\n"));
    env->x = 0;
    while(mappoint[env->x] != '\0')
    {
      env->map[env->y][env->x] = ft_atoi(mappoint[env->x]);
      if (ft_isdigit(env->map[env->y][env->x]) == -1)
        return (ft_error(env, "Error map 1: values are corrupt.\n"));
			if (env->x == 0 || env->x == env->nb_x - 1 || env->y == 0 || env->y == env->nb_y - 1)
				if (env->map[env->y][env->x] == 0)
					return (ft_error(env, "Error map 2: values are corrupt.\n"));
			printf("%s ", mappoint[env->x]);
			env->x++;
    }
		printf("%s", mapline[env->y]);
		printf("\n");
		env->y++;
    if (env->x != env->nb_x)
      return (ft_error(env, "Error map 3: values are corrupt.\n"));
    free_tab_char(mappoint);
  }
  free_tab_char(mapline);
  if (env->y != env->nb_y)
    return (ft_error(env, "Error map 4: values are corrupt.\n"));
}
