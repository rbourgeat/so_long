/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:11:50 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/10 15:21:27 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	size_s1;
	char	*tab;

	count = -1;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	if (!(tab = (char *)malloc((size_s1 + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[++count])
		tab[count] = s1[count];
	count = -1;
	while (s2[++count])
		tab[size_s1 + count] = s2[count];
	tab[size_s1 + count] = '\0';
	return (tab);
}
