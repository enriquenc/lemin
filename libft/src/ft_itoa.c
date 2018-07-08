/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:43:04 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/21 22:32:39 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(intmax_t n)
{
	char			*res;
	int				size;
	intmax_t		i;

	if (n == 0)
		return (ft_strdup("0"));
	size = 1;
	i = n;
	while ((i = i / 10))
		size++;
	if ((res = (char *)malloc(sizeof(*res) * size + 1)) == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	i = n;
	res[size--] = '\0';
	while (i)
	{
		if (i % 10 >= 0)
			res[size--] = i % 10 + 48;
		else
			res[size--] = -1 * (i % 10) + 48;
		i = i / 10;
	}
	return (res);
}
