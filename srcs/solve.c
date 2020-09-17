/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:16:00 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/17 10:59:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /* ===== DELETE ===== */
#include "solve.h"

static void	ft_put_block(int **board, int size, int row, int col)
{
	int	i;

	i = 0;
	while (i < size)
		board[row][col + i++] = 1;
}

static void	ft_rem_block(int **board, int size, int row, int col)
{
	int	i;

	i = 0;
	while (i < size)
		board[row][col + i++] = 0;
}

void		ft_put_board(int **board, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size[1])
	{
		j = 0;
		while (j < size[0])
			write(1, ((board[i][j++]) ?  "# ": ". "), 2);
		write(1, "\n", 1);
		i++;
	}
}

static int	ft_sum_row(int ***args, int row, int num)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[1][row][num + i])
		count += args[1][row][num + i++] + 1;
	return (count - (i > 0));
}

int			ft_solve(int **board, int ***args, int row, int s_col, int *size, int num)
{
	int	col;

	col = 0;
	col += args[1][row][num - 1] + (num > 0) + s_col;
	while (col <= size[0] - args[1][row][num] && col <= size[0] - ft_sum_row(args, row, num))
	{
		ft_put_block(board, args[1][row][num], row, col);
		if (row < size[1] - 1 || args[1][row][num + 1] != 0)
		{
			if (ft_precheck_board(board, args, size, row) && ft_solve(board, args, row + (args[1][row][num + 1] == 0),
				(args[1][row][num + 1] == 0) ? 0 : col, size,
				(args[1][row][num + 1] == 0) ? 0 : num + 1))
				return (1);
			ft_rem_block(board, args[1][row][num], row, col);
		}
		else
		{
			if (ft_check_board(board, args, size))
				return (1);
			ft_rem_block(board, args[1][row][num], row, col);
		}
		col++;
	}
	return (0);
}
