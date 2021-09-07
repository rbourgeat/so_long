/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:22:56 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:22:56 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_is_one(char *str, int first_last_line, int len, t_vars *vars)
{
	int	i;

	if (first_last_line == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != '1')
				__exitc__(1, vars, FAILURE);
			i++;
		}
	}
	else
	{
		if ((str[0] != '1') || (str[len - 1] != '1'))
			__exitc__(1, vars, FAILURE);
	}
	return (1);
}

static int	check_is_nbr(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'C' && str[i] != 'E' && str[i] != 'B')
			__exitc__(2, vars, FAILURE);
		if (BONUS == 0 && str[i] == 'B')
			__exitc__(3, vars, FAILURE);
		i++;
	}
	return (1);
}

static int	check_play(char *str, int r, t_vars *vars)
{
	const char	play[] = {'C', 'E', 'P'};
	static int	nbr[3] = {0};
	int			j;
	int			i;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 3)
		{
			if (str[i] == play[j])
				nbr[j]++;
			j++;
		}
		i++;
	}
	play_loop(nbr, r, vars);
	return (1);
}

void	check_loop(t_check *check, t_vars *vars)
{
	while (check->read > 0)
	{
		check->prev_len = check->len;
		check->read = get_next_line(check->fd, &check->line);
		check->len = ft_strlen(check->line);
		if (check->prev_len != -1 && check->prev_len != check->len)
			__exitc__(6, vars, FAILURE);
		check_play(check->line, check->read, vars);
		check_is_nbr(check->line, vars);
		if (check->i++ == 0 || check->read == 0)
			map_is_one(check->line, 1, check->len, vars);
		else
			map_is_one(check->line, 0, check->len, vars);
		free(check->line);
	}
}

t_check	check_is_map(char *av, t_vars *vars)
{
	t_check	check;

	ft_bzero(&check, sizeof(t_check));
	vars->fail = 0;
	check.len = -1;
	check.read = 1;
	check.fd = open(av, O_RDWR);
	if (check.fd < 0)
		__exitc__(5, vars, FAILURE);
	check_loop(&check, vars);
	close(check.fd);
	__exitc__(0, vars, FAILURE);
	return (check);
}
