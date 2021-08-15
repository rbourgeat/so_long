/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:08:36 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/15 20:27:46 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

#define TEX_PLAYER "./textures/iop.xpm"
#define TEX_WALL "./textures/tree.xpm"
#define TEX_COLLECT "./textures/dofawa.xpm"
#define TEX_EXIT "./textures/zaap.xpm"
#define TEX_ZERO "./textures/grass.xpm"

#define TEX_ENEMY "./textures/bouftou.xpm"

void set_tex(char *path, t_vars *vars, t_img *tex)
{
	const int fd = open(path, O_RDONLY);

	if (fd < 0)
		__exit__("path Error\n", vars, FAILURE);
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		__exit__("path Error\n", vars, FAILURE);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
								  &tex->line_len, &tex->endian);
}

void tex_all(t_vars *vars)
{
	set_tex(TEX_PLAYER, vars, &vars->tex[0]);
	set_tex(TEX_WALL, vars, &vars->tex[1]);
	set_tex(TEX_COLLECT, vars, &vars->tex[2]);
	set_tex(TEX_EXIT, vars, &vars->tex[3]);
	set_tex(TEX_ZERO, vars, &vars->tex[4]);
	set_tex(TEX_ENEMY, vars, &vars->tex[5]);
}