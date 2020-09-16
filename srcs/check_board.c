/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:39:11 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/16 17:23:50 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_board.h"

int ft_is_last_block(int **board, int row, int col, int size)
{
	int	i;

	i = row + 1;
	while (i < size)
	{
		if (board[i++][col] == 1)
			return (0);
	}
	return (1);
}

int	ft_precheck_board(int **board, int ***args, int *size, int row)
{
	int	i;
	int	j;
	int	num;
	int	count;

	i = 0;
	while (i < size[0])
	{
		num = 0;
		j = 0;
		while (args[0][i][num])
		{
			count = 0;
			while (j < size[1] && board[j][i] == 0)
				j++;
			while (j < size[1] && board[j][i] == 1)
			{
				j++;
				count++;
			}
			//if (count > args[0][i][num] || (count < args[0][i][num] && !ft_is_last_block(board, j, i, size[1])))
			if (count > args[0][i][num] || (count < args[0][i][num] && row > j))
				return (0);
			num++;
		}
		while (j < size[1])
			if (board[j++][i] == 1)
				return (0);
		i++;
	}
	return (1);
}

int	ft_check_board(int **board, int ***args, int *size)
{
	int	i;
	int	j;
	int	num;
	int	count;

	i = 0;
	while (i < size[0])
	{
		num = 0;
		j = 0;
		while (args[0][i][num])
		{
			count = 0;
			while (j < size[1] && board[j][i] == 0)
				j++;
			while (j < size[1] && board[j][i] == 1)
			{
				j++;
				count++;
			}
			if (count != args[0][i][num++])
				return (0);
		}
		while (j < size[1])
			if (board[j++][i] == 1)
				return (0);
		i++;
	}
	return (1);
}
