/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:23:37 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:23:38 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_is_file(char *av, t_vars *vars)
{
	int	i;

	i = ft_strlen(av);
	while (av[i] != '.')
	{
		if (i == 0)
			__exit__("Error\n☞ bad file\n", vars, FAILURE);
		i--;
	}
	i++;
	if (ft_strcmp((av + i), "ber") != 0)
		__exit__("Error\n☞ bad file extension\n", vars, FAILURE);
	return (1);
}

void	play_loop(int *nbr, int r, t_vars *vars)
{
	int	i;

	i = 0;
	if (!r)
	{
		while (i < 3)
		{
			if (nbr[i++] < 1 || nbr[2] > 1)
				__exitc__(4, vars, FAILURE);
		}
	}
}
