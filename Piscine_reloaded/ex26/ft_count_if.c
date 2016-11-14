/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:38:37 by psergean          #+#    #+#             */
/*   Updated: 2016/11/11 19:03:10 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
