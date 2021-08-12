/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:11:22 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/07 18:24:05 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > (size_t)ft_strlen(s1))
		n = (size_t)ft_strlen(s1) + 1;
	if (n > (size_t)ft_strlen(s2))
		n = (size_t)ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}
