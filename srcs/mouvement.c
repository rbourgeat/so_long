/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:23:05 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/30 15:56:45 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_mouv2(t_vars *vars)
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

void	data_mouv(t_vars *vars)
{
	if (vars->key->w == 1
		&& vars->map[vars->mouv->y - 1][vars->mouv->x] != '1')
	{
		vars->mouv->y -= 1;
		ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
		ft_putstr("\n");
	}
	else if (vars->key->a == 1
		&& vars->map[vars->mouv->y][vars->mouv->x - 1] != '1')
	{
		vars->mouv->x -= 1;
		ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
		ft_putstr("\n");
	}
	else
		data_mouv2(vars);
}

void	player_mouv(t_vars *vars)
{
	if (vars->key->w == 1 || vars->key->a == 1
		|| vars->key->d == 1 || vars->key->s == 1)
	{
		data_mouv(vars);
		if (vars->map[vars->mouv->y][vars->mouv->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->mouv->y][vars->mouv->x] = '0';
		}
	}
}

int	key_event(t_vars *vars)
{
	if (vars->collect == 0 && vars->map[vars->mouv->y][vars->mouv->x] == 'E')
		__exit__("YOU WIN !\n", vars, SUCCESS);
	else if (vars->map[vars->mouv->y][vars->mouv->x] == 'B')
		__exit__("GAME OVER !\n", vars, SUCCESS);
	else
		player_mouv(vars);
	return (1);
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
