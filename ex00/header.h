/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:23:23 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/20 15:23:26 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

# define N 4

int					ft_puterr(void);

void				ft_putdigit(int d);

int					ft_strlen(char *str);

void				free_matrix(int **matrix, int size);

int					**allocate_matrix(int row, int col);

int					**init_view(char *str);

int					**parse_input(int ac, char **av);

int					**init_grid(int size);

void				print_grid(int **grid, int size);

int					north_view(int **grid, int j);

int					south_view(int **grid, int j);

int					west_view(int **grid, int i);

int					east_view(int **grid, int i);

int					is_row_full(int **grid, int i);

int					is_column_full(int **grid, int j);

int					not_valid_row(int **grid, int **view);

int					not_valid_col(int **grid, int **view);

int					not_in_row(int **grid, int i, int k);

int					not_in_col(int **grid, int j, int k);

int					solver(int **grid, int **view, int position);

#endif
