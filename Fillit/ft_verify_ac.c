/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_ac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:33:13 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 11:33:15 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_verify_ac(int ac)
{
    if (ac < 2)
        ft_exit(1, "usage: ./fillit file_name.\n");
    if (ac > 2)
        ft_exit(1, "invalid arguments : too many files.\n");
}
