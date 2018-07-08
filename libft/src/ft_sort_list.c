/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:40:21 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/28 18:40:23 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_sort_list(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*temp;
	t_list	*res;
	void	*check;

	temp = lst;
	res = lst;
	while (temp->next)
	{
		lst = temp->next;
		while (lst)
		{
			if (!cmp(temp->content, lst->content))
			{
				check = temp->content;
				temp->content = lst->content;
				lst->content = check;
			}
			lst = lst->next;
		}
		temp = temp->next;
	}
	return (res);
}
