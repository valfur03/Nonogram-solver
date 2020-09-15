/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:13:22 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 10:58:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <unistd.h>
# include "check_board.h"

void	ft_put_board(int **board);

int		ft_solve(int **board, int **args, int row, int size);

#endif
