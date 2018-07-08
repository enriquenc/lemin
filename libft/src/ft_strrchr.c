/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 09:46:53 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 09:46:54 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		x;
	const char	*temp;

	x = (char)c;
	temp = s;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
		s++;
	while (temp <= s)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
