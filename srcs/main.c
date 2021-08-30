/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:51:37 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/30 15:16:19 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	event_quit(t_vars *vars)
{
	__exit__(NULL, vars, SUCCESS);
	return (0);
}

void	main2(t_vars *vars, char **argv)
{
	vars->mouv = malloc(sizeof(t_mouv));
	if (!vars->mouv)
		__exit__("Error\n☞ Can't malloc (mouv) !\n", vars, FAILURE);
	vars->key = init_key();
	if (!vars->key)
		__exit__("Error\n☞ Can't malloc (key) !\n", vars, FAILURE);
	parsing(argv[1], vars);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		__exit__("Error\n☞ Can't malloc (img) !\n", vars, FAILURE);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		__exit__("Error\n☞ Can't init mlx !\n", vars, FAILURE);
	vars->win = mlx_new_window(vars->mlx, 100 * vars->map_x_len, 100
			* vars->map_y_len, "so_long by krolhm");
	if (!vars->win)
		__exit__("Error\n☞ Can't create Window !\n", vars, FAILURE);
	vars->img->img = mlx_new_image(vars->mlx, 100
			* vars->map_x_len, 100 * vars->map_y_len);
	if (!vars->img->img)
		__exit__("Error\n☞ Can't mlx image !\n", vars, FAILURE);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		__exit__("Error\n☞ Bad argument !\n", NULL, FAILURE);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		__exit__("Error\n☞ Can't malloc (vars) !\n", vars, FAILURE);
	main2(vars, argv);
	tex_all(vars);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_len,
			&vars->img->endian);
	vars->img->width = 1000;
	vars->img->height = 1000;
	vars->counter = 0;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, RED_CROSS, 1L << 2, event_quit, vars);
	mlx_loop_hook(vars->mlx, event_loop, vars);
	mlx_loop(vars->mlx);
	return (0);
}
