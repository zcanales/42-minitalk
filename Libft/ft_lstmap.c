/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:34:47 by zcanales          #+#    #+#             */
/*   Updated: 2021/08/06 13:08:30 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp)
	{
		if (f)
			temp->content = f(temp->content);
		temp = temp->next;
	}	
	ft_lstclear(&lst, del);
	return (lst);
}
