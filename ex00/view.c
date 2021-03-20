/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:49:20 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:20:59 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					north_view(int **grid, int j)
{
	int				pdv;
	int				max;
	int				i;

	pdv = 0;
	max = 0;
	i = 0;
	while (i < N)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			pdv++;
		}
		i++;
	}
	return (pdv);
}

int					south_view(int **grid, int j)
{
	int				pdv;
	int				max;
	int				i;

	pdv = 0;
	max = 0;
	i = N - 1;
	while (i >= 0)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			pdv++;
		}
		i--;
	}
	return (pdv);
}

int					west_view(int **grid, int i)
{
	int				pdv;
	int				max;
	int				j;

	pdv = 0;
	max = 0;
	j = 0;
	while (j < N)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			pdv++;
		}
		j++;
	}
	return (pdv);
}

int					east_view(int **grid, int i)
{
	int				pdv;
	int				max;
	int				j;

	pdv = 0;
	max = 0;
	j = N - 1;
	while (j >= 0)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			pdv++;
		}
		j--;
	}
	return (pdv);
}
