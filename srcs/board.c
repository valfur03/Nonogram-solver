/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:34:44 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/14 23:02:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

int	**ft_init_board(int	size)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	if (!(tab = malloc(sizeof(*tab) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(**tab) * size)))
			return (NULL);
		while (j < size)
			tab[i][j++] = 0;
		i++;
	}
	return (tab);
}
