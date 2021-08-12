/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:12:23 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/12 13:39:52 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new_lst;

	if (!(new_lst = malloc(sizeof(t_list))))
		return (0);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
