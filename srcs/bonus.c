/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:22:51 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:22:51 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	counter_bonus(t_vars *vars)
{
	const char		*str = ft_itoa(vars->counter);

	if (!str)
		__exit__(NULL, vars, FAILURE);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xFF0000, (char *)str);
	free((char *)str);
}
