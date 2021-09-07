/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:23:07 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:23:07 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pixel_put_color(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dst;

	dst = vars->img->addr + (y * vars->img->line_len + x
			* (vars->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_one_pixe(t_vars *vars, int i, int x_index, int y_index)
{
	const double	pixe_x = ((double)(100 * vars->map_x_len) /
		vars->map_x_len);
	const double	pixe_y = ((double)(100 * vars->map_y_len) /
		vars->map_y_len);
	char			*addr;
	double			x;
	double			y;

	y = 0.0;
	while (y < pixe_y)
	{
		x = 0.0;
		while (x < pixe_x)
		{
			addr = vars->tex[i].addr;
			addr += (size_t)((y / pixe_y) * vars->tex[i].height)
				* vars->tex[i].line_len;
			addr += (size_t)((x / pixe_x) * vars->tex[i].width) * 4;
			pixel_put_color(vars, x + (x_index * pixe_x), y
				+ (y_index * pixe_y), *(unsigned int *)addr);
			x++;
		}
		y++;
	}
}

void	draw_map(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				draw_one_pixe(vars, 2, x, y);
			else if (vars->map[y][x] == 'E')
				draw_one_pixe(vars, 3, x, y);
			else if (vars->map[y][x] == '1')
				draw_one_pixe(vars, 1, x, y);
			else if (vars->map[y][x] == '0')
				draw_one_pixe(vars, 4, x, y);
			else if (vars->map[y][x] == 'B' && BONUS)
				draw_one_pixe(vars, 5, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	draw_player(t_vars *vars)
{
	draw_one_pixe(vars, vars->key->dir, vars->mouv->x, vars->mouv->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
