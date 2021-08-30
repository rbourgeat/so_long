/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:43:04 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/30 13:58:52 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digits(int n)
{
	if ((n / 10) == 0)
		return (1);
	else
		return (ft_get_digits(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				len;
	char			*str;

	nb = (unsigned int)n;
	len = ft_get_digits(n);
	if (n < 0)
	{
		nb = -(unsigned int)n;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len-- >= 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
