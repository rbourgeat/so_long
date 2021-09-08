/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:23:33 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/08 13:54:26 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_mouv(t_vars *vars)
{
	int		i;

	i = 0;
	if (vars->key->w == 1
		&& vars->map[vars->mouv->y - 1][vars->mouv->x] != '1')
	{
		i = 1;
		vars->mouv->y -= 1;
		ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
		ft_putstr("\n");
	}
	else if (vars->key->a == 1
		&& vars->map[vars->mouv->y][vars->mouv->x - 1] != '1')
	{
		i = 1;
		vars->mouv->x -= 1;
		ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
		ft_putstr("\n");
	}
	data_mouv2(vars, i);
}

void	data_mouv2(t_vars *vars, int i)
{
	if (!i)
	{
		if (vars->key->s == 1
			&& vars->map[vars->mouv->y + 1][vars->mouv->x] != '1')
		{
			vars->mouv->y += 1;
			ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
			ft_putstr("\n");
		}
		else if (vars->key->d == 1
			&& vars->map[vars->mouv->y][vars->mouv->x + 1] != '1')
		{
			vars->mouv->x += 1;
			ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
			ft_putstr("\n");
		}
	}
}

void	player_mouv(t_vars *vars)
{
	if ((vars->key->w == 1)
		|| vars->key->a == 1 || vars->key->d == 1 || vars->key->s == 1)
	{
		data_mouv(vars);
		if (vars->map[vars->mouv->y][vars->mouv->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->mouv->y][vars->mouv->x] = '0';
		}
		key_release(KEY_W, vars);
		key_release(KEY_S, vars);
		key_release(KEY_A, vars);
		key_release(KEY_D, vars);
	}
}

int	event_loop(t_vars *vars)
{
	draw_map(vars);
	draw_player(vars);
	key_event(vars);
	if (BONUS)
		counter_bonus(vars);
	return (1);
}

int	__exitc__(int set, t_vars *vars, int ret)
{
	if (!set)
	{
		if (!vars->fail)
			return (0);
		else if (vars->fail == 1)
			__exit__("Error\n☞ Bad map\n", vars, ret);
		else if (vars->fail == 2)
			__exit__("Error\n☞ Bad char in map\n", vars, ret);
		else if (vars->fail == 3)
			__exit__("Error\n☞ Bad bonus in map\n", vars, ret);
		else if (vars->fail == 4)
			__exit__("Error\n☞ Bad map\n", vars, ret);
		else if (vars->fail == 5)
			__exit__("Error\n☞ Map not exist\n", vars, ret);
		else if (vars->fail == 6)
			__exit__("Error\n☞ Map error\n", vars, ret);
	}
	else
		if (!vars->fail)
			vars->fail = set;
	return (0);
}
