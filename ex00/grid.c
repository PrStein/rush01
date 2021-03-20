/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:48:56 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:20:54 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					**init_grid(int size)
{
	int				**grid;
	int				i;
	int				j;

	if (!(grid = allocate_matrix(size, size)))
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}

void				print_grid(int **grid, int size)
{
	int				i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putdigit(grid[i][j]);
			if (j < size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
