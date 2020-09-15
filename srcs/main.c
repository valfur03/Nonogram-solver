/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:38:19 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 18:47:52 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"
#include "check_args.h"
#include "solve.h"
#include <stdio.h> /* ===== DELETE ===== */

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
	board = ft_init_board(size[0], size[1]);
	if (!ft_solve(board, args, 0, 0, size, 0))
		return (0);
	ft_put_board(board, size);
	return (0);
}
