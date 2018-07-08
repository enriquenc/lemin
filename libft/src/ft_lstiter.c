/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 06:48:58 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 06:48:59 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next_list;

	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		next_list = lst->next;
		f(lst);
		lst = next_list;
	}
}
