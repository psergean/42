/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:31:30 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 11:31:31 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_get_file_data(t_base *base, char *filename)
{
    base->file_data.nb_lines = 0;
    base->file_data.nb_chars = 0;
    base->tmp.i = 0;
    base->tmp.tetri_i = 0;
    base->tmp.fd = open(filename, O_RDONLY);
    ft_check_fd(base->tmp.fd);
    base->file_data.nb_chars = read(base->tmp.fd, base->file_data.buff, 545);
    ft_check_ret(base->file_data.nb_chars, 1);
    base->file_data.buff[base->file_data.nb_chars--] = '\0';
    if (base->file_data.nb_chars == 544)
        ft_check_ret(read(base->tmp.fd, base->tmp.str, 2), 2);
    while (base->file_data.buff[base->tmp.i])
    {
        ft_check_chars(base->file_data.buff[base->tmp.i]);
        if (base->file_data.buff[base->tmp.i] == '\n')
        {
            base->file_data.nb_lines++;
        }
        base->tmp.i++;
    }
    ft_check_tetri_max_lines(base->file_data.nb_lines);
    ft_check_tetri_max_chars(base->file_data.nb_chars);
    ft_check_chars_and_lines(base->file_data.nb_chars, base->file_data.nb_lines);
    if (base->file_data.nb_lines > 9)
        base->tetri_max = (base->file_data.nb_lines - 4) / 5 + 1;
    else
        base->tetri_max = 1;
    base->tmp.i = 0;
}
