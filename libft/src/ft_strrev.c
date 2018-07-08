/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 05:27:54 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/02/09 08:05:57 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char *begin;
	char *end;

	if (str == NULL)
		return (NULL);
	begin = str;
	end = str;
	while (*end)
		end++;
	while (begin < --end)
	{
		*begin -= *end;
		*end += *begin;
		*begin = *end - *begin;
		begin++;
	}
	return (str);
}
