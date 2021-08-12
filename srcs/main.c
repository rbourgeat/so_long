/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:51:37 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/12 14:06:48 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int event_quit(t_vars *vars)
{
	__exit__(NULL, vars, SUCCESS);
	return (0);
}

int main(int argc, char **argv)
{
	t_vars	*vars;
	
	if (argc != 2)
		__exit__("Error\n☞ Bad argument !\n", NULL, FAILURE);
	if (!(vars = ft_calloc(sizeof(t_vars), 1)))
		__exit__("Error\n☞ Can't malloc (vars) !\n", vars, FAILURE);
	if (!(vars->mouv = malloc(sizeof(t_mouv))))
		__exit__("Error\n☞ Can't malloc (mouv) !\n", vars, FAILURE);
	if (!(vars->key = init_key()))
		__exit__("Error\n☞ Can't malloc (key) !\n", vars, FAILURE);
	parsing(argv[1], vars);
	if (!(vars->img = malloc(sizeof(t_img))))
		__exit__("Error\n☞ Can't malloc (img) !\n", vars, FAILURE);
	if (!(vars->mlx = mlx_init()))
		__exit__("Error\n☞ Can't init mlx !\n", vars, FAILURE);
	if (!(vars->win = mlx_new_window(vars->mlx, 1000, 1000, "so_long")))
		__exit__("Error\n☞ Can't create Window !\n", vars, FAILURE);
	if (!(vars->img->img = mlx_new_image(vars->mlx, 1000, 1000)))
		__exit__("Error\n☞ Can't mlx image !\n", vars, FAILURE);
	// tex_all(vars);



	return (0);
}