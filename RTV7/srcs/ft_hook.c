/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzaaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:01:48 by tzaaboul          #+#    #+#             */
/*   Updated: 2018/02/28 13:19:43 by tzaaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				close_win(t_env *e)
{
	free_env(e, NULL);
	exit(EXIT_SUCCESS);
	return (1);
}

int				key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
		close_win(e);
	return (1);
}

int				key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		close_win(e);
	return (1);
}

int				ft_loop_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (1);
}
