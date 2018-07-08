/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:55:08 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 13:55:09 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*temp;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((res = (char *)malloc(sizeof(*res) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	temp = res;
	while (*s)
	{
		*res = f(*s);
		res++;
		s++;
	}
	*res = '\0';
	res = temp;
	return (res);
}
