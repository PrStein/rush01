/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:45:30 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:20:43 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					ft_puterr(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void				ft_putdigit(int d)
{
	char			c;

	c = d + 48;
	write(1, &c, 1);
}

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				free_matrix(int **matrix, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
}

int					**allocate_matrix(int row, int col)
{
	int				**matrix;
	int				i;

	if (!(matrix = (int **)malloc(sizeof(int *) * row)))
		return (0);
	i = 0;
	while (i < row)
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * col)))
		{
			free_matrix(matrix, i);
			return (0);
		}
		i++;
	}
	return (matrix);
}
