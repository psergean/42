/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:21:47 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 13:21:49 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    t_base base;

    ft_verify_ac(ac);
    ft_get_file_data(&base, av[1]);
    ft_get_tetri_plan(&base);
    return (0);
}
