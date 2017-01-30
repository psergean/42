/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetri_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:22:43 by psergean          #+#    #+#             */
/*   Updated: 2017/01/26 15:22:48 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_get_tetri_plan(t_base *base)
{
    int x;
    int y;
    int i;
    int count;
    char c;

    x = 0;
    y = 0;
    i = 0;
    count = 0;
    c = 'A';
    while (base->file_data.buff[base->tmp.i])
    {
        while (base->file_data.buff[base->tmp.i] != '\n')
        {
            if (base->file_data.buff[base->tmp.i] == '#')
            {
                count++;
                if (base->file_data.buff[base->tmp.i] == '#' && count == 1)
                    ft_wood_of_if(base);
                base->tetri_data[i].plan[x][y] = c;
            }
            else
                base->tetri_data[i].plan[x][y] = base->file_data.buff[base->tmp.i];
            base->tmp.i++;
            y++;
        }
        while (base->file_data.buff[base->tmp.i] == '\n')
        {
            ft_putstr(base->tetri_data[i].plan[x]);
            ft_putchar('\n');
            if (base->file_data.buff[base->tmp.i] == '\n' && (base->file_data.buff[base->tmp.i + 1] == '\n' ||
                base->file_data.buff[base->tmp.i + 1] == '\0'))
            {
                ft_putchar('\n');
                if (count != 4)
                    ft_exit(1, "invalid Tetriminos : more or less '#' on line\n");
                base->tmp.i++;
                i++;
                x = 0;
                count = 0;
                c += 1;
            }
            if (y != 4)
                ft_exit(1, "invalid Tetriminos : more or less chars on line\n");
            base->tmp.i++;
            x++;
            y = 0;
        }
    }
    base->file_data.buff[base->tmp.i] = 0;
}
