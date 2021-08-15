/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:31:15 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/12 16:39:05 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void get_value(t_vars *vars, t_check check)
{
    int i = 0;
    int j;
    vars->collect = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == 'C')
                vars->collect++;
            if (vars->map[i][j] == 'P')
            {
                vars->mouv->x = j;
                vars->mouv->y = i;
                vars->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    vars->map_x_len = check.len;
    vars->map_y_len = check.i;
}

void parsing(char *av, t_vars *vars)  
{
    t_check check;

    int i = 0;

    check_is_file(av, vars);
    check = check_is_map(av, vars);
    vars->map = ft_calloc(sizeof(char *), (check.i + 1));
    if (!vars->map)
        __exit__(NULL, vars, FAILURE);
    check.fd = open(av, O_RDWR);
    check.read = 1;
    while (check.read)
    {
        check.read = get_next_line(check.fd, &check.line);
        vars->map[i++] = ft_strdup(check.line);
        free(check.line);
    }
    close(check.fd);
    get_value(vars, check);
}
