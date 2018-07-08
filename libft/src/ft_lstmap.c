/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 06:56:08 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 06:56:09 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *lst)
{
	while (lst)
	{
		free(lst->content);
		free(lst);
		lst = lst->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if ((list->next = (t_list*)malloc(sizeof(t_list))) == NULL)
		{
			free_list(new);
			return (NULL);
		}
		if ((list->next = f(lst)) == NULL)
		{
			free_list(new);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
