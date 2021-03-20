/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:51:07 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:21:07 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					not_in_row(int **grid, int i, int k)
{
	int				j;

	j = 0;
	while (j < N)
	{
		if (grid[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int					not_in_col(int **grid, int j, int k)
{
	int				i;

	i = 0;
	while (i < N)
	{
		if (grid[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int					solver(int **grid, int **view, int position)
{
	int				i;
	int				j;
	int				k;

	if (not_valid_row(grid, view) || not_valid_col(grid, view))
		return (0);
	if (position == N * N)
		return (1);
	i = position / N;
	j = position % N;
	k = 1;
	while (k < N + 1)
	{
		if (not_in_row(grid, i, k) && not_in_col(grid, j, k))
		{
			grid[i][j] = k;
			if (solver(grid, view, position + 1))
				return (1);
		}
		k++;
	}
	grid[i][j] = 0;
	return (0);
}

int					main(int argc, char *argv[])
{
	int				**grid;
	int				**view;

	if (!(view = parse_input(argc, argv)))
		return (ft_puterr());
	if (!(grid = init_grid(N)))
	{
		free_matrix(view, 4);
		return (ft_puterr());
	}
	if (!solver(grid, view, 0))
	{
		free_matrix(grid, N);
		free_matrix(view, 4);
		return (ft_puterr());
	}
	print_grid(grid, N);
	free_matrix(grid, N);
	free_matrix(view, 4);
	return (0);
}
