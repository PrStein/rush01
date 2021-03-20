/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:48:23 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:20:51 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					**init_view(char *str)
{
	int				**view;
	int				i;
	int				j;
	int				k;

	if (!(view = allocate_matrix(4, N)))
		return (0);
	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < N)
		{
			view[i][j] = str[k] - 48;
			k += 2;
			j++;
		}
		i++;
	}
	return (view);
}

int					**parse_input(int ac, char **av)
{
	int				i;

	if (ac != 2)
		return (0);
	if (ft_strlen(av[1]) != N * 8 - 1)
		return (0);
	i = 0;
	while (av[1][i])
	{
		if (i % 2 && av[1][i] != 32)
			return (0);
		if (!(i % 2) && (av[1][i] < 48 || av[1][i] > 57))
			return (0);
		i++;
	}
	return (init_view(av[1]));
}
