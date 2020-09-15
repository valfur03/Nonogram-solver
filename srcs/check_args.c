/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:32:29 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/14 21:52:48 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"
#include <stdio.h> /* ===== DELETE ===== */

int	ft_check_args(char *arg, int **tab)
{
	int		i;
	int		j;
	int		size;
	char	**str;

	i = 0;
	size = 5;
	str = &arg;
	while (i < 2)
	{
		j = 0;
		tab[i] = malloc(sizeof(**tab) * size);
		while (j < size)
		{
			if (**str < '0' || **str > '9')
				return (0);
			tab[i][j++] = ft_atoi(str);
			(*str)++;
		}
		i++;
	}
	return (size);
}
