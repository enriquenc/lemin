/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:38:38 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 14:38:39 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*temp;

	if (s == NULL)
		return (NULL);
	if ((res = (char *)malloc(sizeof(*res) * (len + 1))) == NULL)
		return (NULL);
	temp = res;
	while (len)
	{
		*res = s[start];
		res++;
		start++;
		len--;
	}
	*res = '\0';
	res = temp;
	return (res);
}
