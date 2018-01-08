/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:02:36 by psergean          #+#    #+#             */
/*   Updated: 2017/10/29 14:45:14 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/rtv1.h"

// void			free_tab_int(int **tab)
// {
// 	int		i;
//
// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }
//
// void			free_tab_char(char **tab)
// {
// 	int		i;
//
// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

void			free_malloc(t_env *env)
{
	free(env->cam->vpul);
	free(env->cam);
	free(env);
}
