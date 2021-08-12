/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:22:04 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/12 13:28:42 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_key	*init_key(void)
{
	t_key	*key;
	
	key = malloc(sizeof(t_key));
	if (!key)
		return (NULL);
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	return (key);
}

int key_press(int keycode, t_vars *vars)
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
    return (1);
}

int key_release(int keycode, t_vars *vars)
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

void data_mouv(t_vars *vars)
{
    if (vars->key->w == 1 && vars->map[vars->mouv->y - 1][vars->mouv->x] != '1')
    {
        vars->mouv->y -= 1;
        ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
        ft_putstr("\n");
    }
    else if (vars->key->a == 1 && vars->map[vars->mouv->y][vars->mouv->x - 1] != '1')
    {
        vars->mouv->x -= 1;
        ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
        ft_putstr("\n");
    }
    else if (vars->key->s == 1 && vars->map[vars->mouv->y + 1][vars->mouv->x] != '1')
    {
        vars->mouv->y += 1;
        ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
        ft_putstr("\n");
    }
    else if (vars->key->d == 1 && vars->map[vars->mouv->y][vars->mouv->x + 1] != '1')
    {
        vars->mouv->x += 1;
        ft_putnbr_fd(++vars->counter, STDOUT_FILENO);
        ft_putstr("\n");
    }
}

void player_mouv(t_vars *vars)
{

    if (vars->key->w == 1 || vars->key->a == 1 || vars->key->d == 1 || vars->key->s == 1)
    {
        data_mouv(vars);
        if (vars->map[vars->mouv->y][vars->mouv->x] == 'C')
        {
            vars->collect--;
            vars->map[vars->mouv->y][vars->mouv->x] = '0';
        }
    }
}

int key_event(t_vars *vars)
{

    if (vars->collect == 0 && vars->map[vars->mouv->y][vars->mouv->x] == 'E')
        __exit__("YOU WIN !\n", vars, SUCCESS);
    else
        player_mouv(vars);
    return (1);
}

// int event_loop(t_vars *vars)
// {
//     draw_map(vars);
//     draw_player(vars);
//     key_event(vars);
//     if (BONUS)
//         counter_bonus(vars);
//     return (1);
// }