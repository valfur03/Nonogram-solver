/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:16:00 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 15:51:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_put_board(int **board)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 5;
	while (i < size)
	{
		j = 0;
		while (j < size)
			write(1, ((board[i][j++]) ?  "#": "."), 1);
		write(1, "\n", 1);
		i++;
	}
}

int			ft_solve(int **board, int ***args, int row, int size, int num)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (i < num)
		col += args[1][row][i++] + 1;
	while (col <= size - args[1][row][num])
	{
		ft_put_block(board, args[1][row][num], row, col);
		if (row < size - 1 || args[1][row][num + 1] != 0)
		{
			if (ft_solve(board, args, row + (args[1][row][num + 1] == 0), size,
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
