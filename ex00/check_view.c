/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:50:12 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:21:03 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					is_row_full(int **grid, int i)
{
	int				j;

	j = 0;
	while (j < N)
	{
		if (grid[i][j] == 0)
			return (0);
		j++;
	}
	return (1);
}

int					is_column_full(int **grid, int j)
{
	int				i;

	i = 0;
	while (i < N)
	{
		if (grid[i][j] == 0)
			return (0);
		i++;
	}
	return (1);
}

int					not_valid_row(int **grid, int **view)
{
	int				i;

	i = 0;
	while (i < N)
	{
		if (is_row_full(grid, i))
		{
			if (west_view(grid, i) != view[2][i])
				return (1);
			if (east_view(grid, i) != view[3][i])
				return (1);
		}
		i++;
	}
	return (0);
}

int					not_valid_col(int **grid, int **view)
{
	int				j;

	j = 0;
	while (j < N)
	{
		if (is_column_full(grid, j))
		{
			if (north_view(grid, j) != view[0][j])
				return (1);
			if (south_view(grid, j) != view[1][j])
				return (1);
		}
		j++;
	}
	return (0);
}
