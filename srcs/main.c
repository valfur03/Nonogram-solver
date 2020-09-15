/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:38:19 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 10:57:54 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /* ===== DELETE ===== */
#include "board.h"
#include "check_args.h"
#include "solve.h"

int		main(int argc, char **argv)
{
	int	size;
	int	*args[2];
	int	**board;

	if (argc != 2)
		return (0);
	args[0] = NULL;
	args[1] = NULL;
	if (!(size = ft_check_args(argv[1], args)))
		return (0);
	board = ft_init_board(size);
	if (!ft_solve(board, args, 0, size))
		return (0);
	ft_put_board(board);
	return (0);
}
