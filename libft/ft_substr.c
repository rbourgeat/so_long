/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:11:27 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/12 15:43:54 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len2;

	str = NULL;
	if (s != NULL)
	{
		len2 = ft_strlen(s);
		if (len > len2)
			len = len2;
		if (start > len2)
			start = len2;
		if (start + len > len2)
			len = len2 - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			ft_memmove(str, s + start, len);
			str[len] = '\0';
		}
	}
	return (str);
}
