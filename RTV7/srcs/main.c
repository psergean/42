/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:06:46 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/03/07 19:47:32 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		init_env(t_env *e)
{
	e->conf = NULL;
	e->obj = NULL;
	e->light = NULL;
}

static void		init_mlx(t_env *e, char *file)
{
	if ((e->mlx_ptr = mlx_init()) == NULL)
		ft_error("Error: mlx_init failed\n");
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT,
					file)) == NULL)
		ft_error("Error: mlx_new_window failed\n");
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT)) == NULL)
		ft_error("Error: mlx_new_image failed\n");
	if ((e->img_addr = mlx_get_data_addr(e->img_ptr, &(e->bpp),
					&(e->sline), &(e->endian))) == NULL)
		ft_error("Error: mlx_get_data_addr failed\n");
}

static void		display_help(void)
{
	char		*line;
	int			fd;

	fd = ft_open("conf_files/conf_exemple.txt", O_RDONLY);
	ft_putstr("conf_file exemple:\n");
	while (get_next_line(fd, &line))
		ft_putendl(line);
	ft_close(fd);
	exit(EXIT_SUCCESS);
}

static void		ft_loop(t_env *e)
{
	mlx_do_key_autorepeatoff(e->mlx_ptr);
	mlx_expose_hook(e->win_ptr, ft_loop_hook, e);
	mlx_hook(e->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_hook(e->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release, e);
	mlx_hook(e->win_ptr, 17, 1, close_win, e);
	mlx_loop_hook(e->mlx_ptr, ft_loop_hook, e);
	mlx_loop(e->mlx_ptr);
}

int				main(int ac, char **av)
{
	t_env		*e;

	if (ac != 2)
		ft_error("usage: ./rtv1 conf_file\n       ./rtv1 -h\n");
	if (!ft_strcmp(av[1], "-h"))
		display_help();
	e = (t_env *)ft_malloc(sizeof(*e));
	init_env(e);
	init_val(e, av[1]);
	init_mlx(e, av[1]);
	rt(e);
	ft_loop(e);
	return (1);
}
