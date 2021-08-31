/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:20:33 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:20:33 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > (size_t)ft_strlen(s1))
		n = (size_t)ft_strlen(s1) + 1;
	if (n > (size_t)ft_strlen(s2))
		n = (size_t)ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}
