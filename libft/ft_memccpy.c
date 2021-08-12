/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:29:40 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/12 13:17:36 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str, const void *ptr, int c, size_t n)
{
	unsigned	char		*str1;
	unsigned	char		*ptr1;
	size_t					i;

	str1 = (unsigned char *)str;
	ptr1 = (unsigned char *)ptr;
	if (!str1 && !ptr1)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		str1[i] = ptr1[i];
		if (ptr1[i] == (unsigned char)c)
		{
			return (str1 + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
