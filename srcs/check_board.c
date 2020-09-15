/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:39:11 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 10:55:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_board.h"

int	ft_check_board(int **board, int **args, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			while (j < size && board[j][i] == 0)
				j++;
			while (j < size && board[j][i] == 1)
			{
				j++;
				count++;
			}
			if (count != args[0][i])
				return (0);
		}
		i++;
	}
	return (1);
}
