/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:17:42 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/12 14:44:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*str;
	unsigned	char	b;
	int					i;

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
