/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:32:29 by vfurmane          #+#    #+#             */
/*   Updated: 2020/09/15 15:26:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

static int	ft_get_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] && str[i] != ' ')
	{
		if (str[i++] == ',')
		{
			if (str[i] > '0' && str[i] < '9' )
				count++;
			else
				return (0);
		}
	}
	return (count);
}

int			ft_check_args(char *arg, int ***tab)
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		numbers;
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
			numbers = ft_get_numbers(*str);
			if (!(tab[i][j] = malloc(sizeof(***tab) * (numbers + 1))))
				return (0);
			k = 0;
			while (k < numbers && **str)
			{
				if (**str && (**str < '0' || **str > '9'))
					return (0);
				tab[i][j][k++] = ft_atoi(str);
				if (**str)
					(*str)++;
			}
			tab[i][j++][k] = 0;
		}
		i++;
	}
	return (size);
}
