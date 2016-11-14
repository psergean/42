/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:02:54 by psergean          #+#    #+#             */
/*   Updated: 2016/11/11 19:00:09 by psergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	return (s1[index] - s2[index]);
}

int		main(int ac, char **av)
{
	int		index;
	char	*tmp;

	index = 1;
	while (index < (ac - 1))
	{
		while (ft_strcmp(av[index], av[index + 1]) > 0)
		{
			tmp = av[index];
			av[index] = av[index + 1];
			av[index + 1] = tmp;
			index = 1;
		}
		index++;
	}
	index = 1;
	while (index < ac)
	{
		ft_putstr(av[index]);
		ft_putchar('\n');
		index++;
	}
	return (0);
}
