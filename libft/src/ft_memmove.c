/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:57:33 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/22 21:06:55 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*desti;
	size_t			i;

	if (len <= 0)
		return (dst);
	source = (unsigned char *)src;
	desti = (unsigned char *)dst;
	i = 0;
	if (source < desti)
	{
		while (len-- > 0)
			desti[len] = source[len];
	}
	else
		ft_memcpy(desti, source, len);
	return (dst);
}
