/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:15:18 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/04 15:15:27 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned	int		i;
	unsigned	char	*c;

	i = 0;
	c = (unsigned char *)pointer;
	while (i < count)
		c[i++] = (unsigned char)value;
	pointer = (void *)c;
	return (pointer);
}
