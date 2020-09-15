/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:39:11 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 16:27:24 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_board.h"

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
		i++;
	}
	return (1);
}
