/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:46:25 by psergean          #+#    #+#             */
/*   Updated: 2017/08/23 15:07:06 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void		ft_exit(t_env *env)
{
	free(env);
	exit(0);
	return ;
}

int			check_input(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage:./fdf file_map.\n", 2);
		return (0);
	}
	return (1);
}

int			check_file(t_env *env)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while(env->file[i] != '\0')
	{
		if (env->file[i] == '\n' || env->file[i] == '\0')
			y++;
		if (ft_isalpha(env->file[i]) || env->file[i] == '\t')
		{
			ft_putstr_fd("Error: Value is corrupt.\n", 2);
			ft_exit(env);
		}
		i++;
	}
	if (y <= 1)
	{
		ft_putstr_fd("Error: Empty file or missing line on file.\n", 2);
		ft_exit(env);
	}
	return (1);
}
