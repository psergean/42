/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <tzaaboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:06:46 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/02/01 17:05:11 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#include <stdio.h>

static void		init_env(t_env *e)
{
	e->conf = NULL;
	e->cam = NULL;
	e->obj = NULL;
	e->light = NULL;
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
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "rtv1");
	e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->img_addr = mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->sline), &(e->endian));
	get_vp(e->cam);
	rt(e);
mlx_loop(e->mlx_ptr);
	return (1);
}
