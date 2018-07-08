/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:49:21 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/22 20:13:07 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*source;
	unsigned char	x;

	desti = (unsigned char *)dst;
	source = (unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*desti = *source;
		if (*source == x)
			return (desti + 1);
		desti++;
		source++;
		i++;
	}
	return (NULL);
}
