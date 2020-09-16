/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:38:19 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/16 11:11:25 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"
#include "check_args.h"
#include "solve.h"
#include <stdio.h> /* ===== DELETE ===== */

void	ft_free_all(int ***args, int **board, int *size)
{
	int	i;

	i = 0;
	while (i < size[0])
		free(board[i++]);
	free(board);
	i = 0;
	while (i < size[0])
		free(args[0][i++]);
	i = 0;
	while (i < size[1])
		free(args[1][i++]);
	free(args[0]);
	free(args[1]);
	free(size);
}

int		main(int argc, char **argv)
{
	int	*size;
	int	**args[2];
	int	**board;

	if (argc != 2)
		return (0);
	args[0] = NULL;
	args[1] = NULL;
	if (!(size = ft_check_args(argv[1], args)))
		return (0);
	if (!(board = ft_init_board(size[0], size[1])))
		return (0);
	if (!ft_solve(board, args, 0, 0, size, 0))
		return (0);
	ft_put_board(board, size);
	ft_free_all(args, board, size);
	return (0);
}
