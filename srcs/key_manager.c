/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:23:12 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/03 11:29:10 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_key	*init_key(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (NULL);
	key->dir = 0 ;
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	return (key);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 0)
		vars->key->w = 1;
	else if (keycode == KEY_A && vars->key->a == 0)
		vars->key->a = 1;
	else if (keycode == KEY_S && vars->key->s == 0)
		vars->key->s = 1;
	else if (keycode == KEY_D && vars->key->d == 0)
		vars->key->d = 1;
	if (BONUS)
		bonus_key(keycode, vars);
	return (1);
}

void	bonus_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_A && vars->key->a == 1)
		vars->key->dir = 6;
	else if (keycode == KEY_D && vars->key->d == 1)
		vars->key->dir = 0;
}

/*	
**	else if (keycode == KEY_W && vars->key->w == 1)
**		vars->key->dir = 7;
**	else if (keycode == KEY_S && vars->key->s == 1)
**		vars->key->dir = 8;
*/

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 1)
		vars->key->w = 0;
	else if (keycode == KEY_A && vars->key->a == 1)
		vars->key->a = 0;
	else if (keycode == KEY_S && vars->key->s == 1)
		vars->key->s = 0;
	else if (keycode == KEY_D && vars->key->d == 1)
		vars->key->d = 0;
	return (1);
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
