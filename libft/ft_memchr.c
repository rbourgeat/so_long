/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:18:45 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/31 14:18:45 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	b;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (str[i] == b)
			return (str + i);
		i++;
	}
	return (NULL);
}
