/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:13:22 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 16:55:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <unistd.h>
# include "check_board.h"

void	ft_put_board(int **board, int *size);

int		ft_solve(int **board, int ***args, int row, int col, int *size, int num);

#endif
