/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:34:44 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 16:24:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

int	**ft_init_board(int	x, int y)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	if (!(tab = malloc(sizeof(*tab) * y)))
		return (NULL);
	while (i < y)
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(**tab) * x)))
			return (NULL);
		while (j < x)
			tab[i][j++] = 0;
		i++;
	}
	return (tab);
}
