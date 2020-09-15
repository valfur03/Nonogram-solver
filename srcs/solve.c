/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:16:00 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 10:59:36 by vfurmane         ###   ########.fr       */
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

int			ft_solve(int **board, int **args, int row, int size)
{
	int	col;

	col = 0;
	while (col <= size - args[1][row])
	{
		ft_put_block(board, args[1][row], row, col);
		if (row < size - 1)
		{
			if (ft_solve(board, args, row + 1, size))
				return (1);
			ft_rem_block(board, args[1][row], row, col);
		}
		else
		{
			if (ft_check_board(board, args, size))
				return (1);
			ft_rem_block(board, args[1][row], row, col);
		}
		col++;
	}
	return (0);
}
