/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wood_of_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:55 by psergean          #+#    #+#             */
/*   Updated: 2017/01/30 17:22:59 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_wood_of_if(t_base *base)
{
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 2] == '#' && base->file_data.buff[base->tmp.i + 3] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 2] == '#' && base->file_data.buff[base->tmp.i + 7] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 4] == '#' && base->file_data.buff[base->tmp.i + 5] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 5] == '#' && base->file_data.buff[base->tmp.i + 6] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 6] == '#' && base->file_data.buff[base->tmp.i + 7] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 6] == '#' && base->file_data.buff[base->tmp.i + 11] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 2] == '#' && base->file_data.buff[base->tmp.i + 6] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 10] == '#' && base->file_data.buff[base->tmp.i + 15] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 4] == '#' &&
        base->file_data.buff[base->tmp.i + 5] == '#' && base->file_data.buff[base->tmp.i + 9] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 6] == '#' && base->file_data.buff[base->tmp.i + 10] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 4] == '#' &&
        base->file_data.buff[base->tmp.i + 5] == '#' && base->file_data.buff[base->tmp.i + 6] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 4] == '#' &&
        base->file_data.buff[base->tmp.i + 5] == '#' && base->file_data.buff[base->tmp.i + 10] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 6] == '#' && base->file_data.buff[base->tmp.i + 11] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 6] == '#' && base->file_data.buff[base->tmp.i + 7] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 9] == '#' && base->file_data.buff[base->tmp.i + 10] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 3] == '#' &&
        base->file_data.buff[base->tmp.i + 4] == '#' && base->file_data.buff[base->tmp.i + 5] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 2] == '#' && base->file_data.buff[base->tmp.i + 5] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 5] == '#' &&
        base->file_data.buff[base->tmp.i + 10] == '#' && base->file_data.buff[base->tmp.i + 11] == '#')
        return (0);
    if (base->file_data.buff[base->tmp.i] == '#' && base->file_data.buff[base->tmp.i + 1] == '#' &&
        base->file_data.buff[base->tmp.i + 5] == '#' && base->file_data.buff[base->tmp.i + 10] == '#')
        return (0);
    else
        ft_exit(1, "invalid Tetriminos : piece not exist.\n");
    return (0);
}
