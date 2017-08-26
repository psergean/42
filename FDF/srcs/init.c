/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2017/08/23 16:01:55 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

int			read_file(t_env *env)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

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

t_env		*init_env(t_env *env, char **av)
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

void		init_calc(t_env *env, t_calc *calc, int i, int j)
{
	calc->xi = env->coord_f[i].xi;
	calc->yi = env->coord_f[i].yi;
	calc->dx = env->coord_f[j].xi - env->coord_f[i].xi;
	calc->dy = env->coord_f[j].yi - env->coord_f[i].yi;
	calc->xinc = (calc->dx >= 0) ? 1 : -1;
	calc->yinc = (calc->dy >= 0) ? 1 : -1;
	calc->z = env->coord[j].z;
	//calc->dx = ABS(calc->dx);
	//calc->dy = ABS(calc->dy);
	calc->dx = (calc->dx >= 0) ? calc->dx : -calc->dx;
	calc->dy = (calc->dy >= 0) ? calc->dy : -calc->dy;
//  printf("xinc = %d ", calc->xinc);
//  printf("yinc = %d\n", calc->yinc);
//  printf("%d ", calc->yi);
//  printf("%d\n\n", calc->yf);
//  printf("env->coord_f[%d] xi = %f ", j, env->coord_f[j].xi);
//  printf("env->coord_f[%d] yi = %f\n", j, env->coord_f[j].yi);
//  printf("env->coord_f[%d] xf = %f ", j, env->coord_f[j].xf);
//  printf("env->coord_f[%d] yf = %f\n\n", j, env->coord_f[j].yf);
//  printf("env->coord[%d] xi = %d ", j, env->coord[j].xi);
//  printf("env->coord[%d] yi = %d\n", j, env->coord[j].yi);
//  printf("env->coord[%d] xf = %d ", j, env->coord[j].xf);
//  printf("env->coord[%d] yf = %d\n\n", j, env->coord[j].yf);
}

void		init_coord(t_env *env, int x, int y, int k)
{
	env->coord[k].xi = x * 35;
	env->coord[k].yi = y * 35;
	env->coord[k].z = ft_atoi(env->x_split[x - 1]) * 8;
}

void		init_max(t_env *env)
{
	int		x;
	int		y;

	env->y_split = ft_strsplit(env->file, '\n');
	env->x_split = ft_strsplit(env->y_split[1], ' ');
	x = 0;
	while (env->x_split[x] != '\0')
		x++;
	env->nb_x = x;
	y = 0;
	while (env->y_split[y] != '\0')
		y++;
	env->nb_y = y;
}
