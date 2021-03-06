/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:24:36 by psergean          #+#    #+#             */
/*   Updated: 2017/09/13 16:43:38 by psergean         ###   ########.fr       */
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
		free(env->file);
		env->file = ft_strdup(tmp);
		free(tmp);
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
	env->win = mlx_new_window(env->mlx, 1260, 980, "FdF");
	env->file = ft_strnew(0);
	if ((env->fd = open(av[1], O_RDONLY)) < 0 || !(read_file(env)))
	{
		perror(av[1]);
		ft_exit(env);
	}
	if (!(check_file(env)))
		ft_exit(env);
	env->nb_x = 0;
	env->nb_y = 0;
	init_max(env);
	env->nb = env->nb_x * env->nb_y;
	env->zinc = 5;
	env->dec_x = 600;
	env->dec_y = 300;
	env->zoom = 35;
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
	calc->z = env->coord[i].z;
	calc->dx = ABS(calc->dx);
	calc->dy = ABS(calc->dy);
}

void		init_coord(t_env *env, int x, int y, int k)
{
	env->coord[k].xi = x * env->zoom;
	env->coord[k].yi = y * env->zoom;
	env->coord[k].z = ft_atoi(env->x_split[x - 1]) * env->zinc;
	if (env->coord[k].z <= -50000 || env->coord[k].z >= 50000)
		ft_error(env, "Error: Value is too small or too large.\n");
	if (env->coord[k].xi <= -50000 || env->coord[k].xi >= 50000)
		ft_error(env, "Error: Value is too small or too large.\n");
	if (env->coord[k].yi <= -50000 || env->coord[k].yi >= 50000)
		ft_error(env, "Error: Value is too small or too large.\n");
}

void		init_max(t_env *env)
{
	int		i;
	int		x;
	int		y;

	env->y_split = ft_strsplit(env->file, '\n');
	env->x_split = ft_strsplit(env->y_split[0], ' ');
	x = 0;
	while (env->x_split[x] != '\0')
		x++;
	env->nb_x = x;
	free_tab(env->x_split);
	y = 0;
	i = 0;
	while (env->y_split[y] != '\0')
	{
		env->x_split = ft_strsplit(env->y_split[y], ' ');
		while (env->x_split[i] != '\0')
			i++;
		free_tab(env->x_split);
		y++;
	}
	env->nb_y = y;
	if (i % env->nb_x != 0)
		ft_error(env, "Error: Value is missing on file.\n");
}
